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

#include "frame.hpp"
#include "udpconnection.hpp"

#include <boost/asio.hpp>

using boost::asio::ip::udp;

namespace sfge::network
{
    class Client
    {
    public:
        explicit Client(boost::asio::io_service &ios);
        ~Client() = default;

        void setOnMessageReceived(std::function<void(const Frame &)> f);

        void sendRequest(const Frame &frame);
        void sendRequest(const std::string &host, uint16_t port, const char *data, std::size_t len);

    private:
        UdpConnection m_connection;
    };
}// namespace sfge::network