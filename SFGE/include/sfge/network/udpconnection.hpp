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

#include <boost/asio.hpp>

using boost::asio::ip::udp;

namespace sfge::network
{
    class UdpConnection
    {
    public:
        explicit UdpConnection(boost::asio::io_service &ios);
        ~UdpConnection() = default;

        void open();
        void bind(int16_t port);

        void read();

        void write(const frame &frame);
        void write(const char *data, std::size_t len, const udp::endpoint &endpoint);

        void setOnMessageReceived(std::function<void(const Frame &)> frame);

    private:
        void doWrite(const frame &frame);
        void doRead(const boost::system::error_code &errorCode, std::size_t len);

    private:
        udp::socket m_socket;
        udp::endpoint m_recvEndpoint;
        boost::asio::streambuf m_recvData;
        std::function<void(const frame &)> m_onMessageReceived;
    };
}// namespace sfge::network
