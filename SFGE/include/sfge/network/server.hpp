//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include "udpconnection.hpp"

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/core/noncopyable.hpp>

using boost::asio::ip::udp;

namespace sfge::network
{
    class Server
    {
    public:
        explicit Server(boost::asio::io_service &ios);
        ~Server() = default;

        void start(int16_t port);
        void setOnMessageReceived(std::function<void(const Frame &)> frame);

        void sendResponse(const Frame &frame);
        void sendResponse(const udp::endpoint &endpoint, const char *data, std::size_t len);

    private:
        UdpConnection m_connection;
    };
}// namespace sfge::network
