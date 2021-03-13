#include <network/udp_connection.hpp>

#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <iostream>

BEGIN_NAMESPACE

udp_connection::udp_connection(boost::asio::io_service &ios)
  : socket_(ios)
{
}

void udp_connection::open()
{
  socket_.open(udp::v4());
}

void udp_connection::bind(int16_t port)
{
  open();
  socket_.bind(udp::endpoint(udp::v4(), port));
}

void udp_connection::read()
{
  socket_.async_receive_from(recv_data_.prepare(1024), recv_endpoint_,
      boost::bind(&udp_connection::do_read, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
}

void udp_connection::write(const network::frame &frame)
{
  if (!socket_.is_open())
    throw std::runtime_error("socket not opened");
  socket_.get_io_service().post(boost::bind(&udp_connection::do_write, this, frame));
}

void udp_connection::write(const char *data, std::size_t len, const udp::endpoint &endpoint)
{
  write({ data, len, endpoint });
}

void udp_connection::set_on_message_received(std::function<void(const frame &frame)> f)
{
  on_message_received_ = f;
}

void udp_connection::do_write(const frame &frame)
{
  socket_.send_to(boost::asio::buffer(frame.data, frame.len), frame.endpoint);
}

void udp_connection::do_read(const boost::system::error_code &ec, std::size_t len)
{
  if (ec) {
    std::cerr << "udp_connection::do_read() error=" << ec << std::endl;
    return ;
  }

  const char *data = boost::asio::buffer_cast<const char *>(recv_data_.data());
  recv_data_.consume(len);

  read();

  if (on_message_received_)
    on_message_received_({ data, len, recv_endpoint_ });
}

END_NAMESPACE
