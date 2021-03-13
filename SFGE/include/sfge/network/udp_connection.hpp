#pragma once

#include <network/frame.hpp>
#include <network/config.hpp>

#include <boost/asio.hpp>

using boost::asio::ip::udp;

BEGIN_NAMESPACE

class udp_connection
{
public:
  explicit udp_connection(boost::asio::io_service &ios);
  ~udp_connection() = default;

  void open();
  void bind(int16_t port);

  void read();

  void write(const frame &frame);
  void write(const char *data, std::size_t len, const udp::endpoint &endpoint);

  void set_on_message_received(std::function<void(const frame &frame)> f);

private:
  void do_write(const frame &frame);
  void do_read(const boost::system::error_code &ec, std::size_t len);

private:
  udp::socket socket_;
  udp::endpoint recv_endpoint_;
  boost::asio::streambuf recv_data_;

  std::function<void(const frame &)> on_message_received_;
};

END_NAMESPACE