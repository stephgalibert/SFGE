#include <network/server.hpp>
#include <network/global.hpp>

#include <iostream>

BEGIN_NAMESPACE
  
server::server(boost::asio::io_service &ios)
  : connection(ios)
{
}

void server::start(int16_t port)
{
  connection.bind(port);
  connection.read();
}

void server::set_on_message_received(std::function<void(const frame &)> f)
{
  connection.set_on_message_received(f);
}

void server::send_response(const frame &frame)
{
  connection.write(frame);
}

void server::send_response(const udp::endpoint &endpoint, const char *data, std::size_t len)
{
  send_response({ data, len, endpoint });
}

END_NAMESPACE