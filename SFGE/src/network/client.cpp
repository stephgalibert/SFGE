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

#include "sfge/network/client.hpp"

namespace sfge::network
{
    Client::Client(boost::asio::io_service &ios)
        : m_connection(ios)
    {
        m_connection.open();
        m_connection.read();
    }

    void Client::setOnMessageReceived(std::function<void(const network::Frame &)> frame)
    {
        m_connection.setOnMessageReceived(frame);
    }

    void Client::sendRequest(const Frame &frame)
    {
        m_connection.write(frame);
    }

    void Client::sendRequest(const std::string &host, uint16_t port, const char *data, std::size_t len)
    {
        udp::endpoint destination(boost::asio::ip::address::from_string(host), port);
        sendRequest({data, len, destination});
    }
}// namespace sfge::network
