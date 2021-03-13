#pragma once

#include <network/frame.hpp>
#include <network/udp_connection.hpp>
#include <network/config.hpp>

#include <boost/asio.hpp>

using boost::asio::ip::udp;

BEGIN_NAMESPACE

class NETWORK_API client
{
public:
  client(boost::asio::io_service &ios);
  ~client() = default;

  void set_on_message_received(std::function<void(const frame &)> f);

  void send_request(const frame &frame);
  void send_request(const std::string &host, uint16_t port, const char *data, std::size_t len);

private:
  udp_connection connection;

};

END_NAMESPACE