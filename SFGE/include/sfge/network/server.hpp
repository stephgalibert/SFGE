#pragma once

#include <network/udp_connection.hpp>
#include <network/config.hpp>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/core/noncopyable.hpp>

using boost::asio::ip::udp;

BEGIN_NAMESPACE

// TODO: private
class NETWORK_API server
{
public:
  explicit server(boost::asio::io_service &ios);
  ~server() = default;

  void start(int16_t port);
  void set_on_message_received(std::function<void(const frame &)> f);

  void send_response(const frame &frame);
  void send_response(const udp::endpoint &endpoint, const char *data, std::size_t len);

private:
  udp_connection connection;
};

END_NAMESPACE
