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

#include "sfge/network/server.hpp"

namespace sfge::network
{
    Server::Server(boost::asio::io_service &ios)
        : m_connection(ios)
    {
    }

    void Server::start(int16_t port)
    {
        m_connection.bind(port);
        m_connection.read();
    }

    void Server::setOnMessageReceived(std::function<void(const Frame &)> frame)
    {
        m_connection.setOnMessageReceived(frame);
    }

    void Server::sendResponse(const Frame &frame)
    {
        m_connection.write(frame);
    }

    void Server::sendResponse(const udp::endpoint &endpoint, const char *data, std::size_t len)
    {
        sendResponse({data, len, endpoint});
    }
}// namespace sfge::network
