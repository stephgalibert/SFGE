#pragma once

#include <network/config.hpp>

#include <boost/asio.hpp>

BEGIN_NAMESPACE

struct frame
{
  const char *data;
  std::size_t len;
  boost::asio::ip::udp::endpoint endpoint;
};

END_NAMESPACE