#include <network/client.hpp>

#include <iostream>

BEGIN_NAMESPACE

using boost::asio::ip::udp;

client::client(boost::asio::io_service &ios)
  : connection(ios)
{
  connection.open();
  connection.read();
}

void client::set_on_message_received(std::function<void(const network::frame &)> f)
{
  connection.set_on_message_received(f);
}

void client::send_request(const frame &frame)
{
  connection.write(frame);
}

void client::send_request(const std::string &host, uint16_t port, const char *data, std::size_t len)
{
  udp::endpoint destination(boost::asio::ip::address::from_string(host), port);
  send_request({ data, len, destination });
}

END_NAMESPACE