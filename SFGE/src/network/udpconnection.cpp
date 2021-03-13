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

#include "sfge/network/udpconnection.hpp"

#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <iostream>

namespace sfge::network
{
    UdpConnection::UdpConnection(boost::asio::io_service &ios)
        : m_socket(ios)
    {
    }

    void UdpConnection::open()
    {
        m_socket.open(udp::v4());
    }

    void UdpConnection::bind(int16_t port)
    {
        open();
        m_socket.bind(udp::endpoint(udp::v4(), port));
    }

    void UdpConnection::read()
    {
        m_socket.async_receive_from(m_recvData.prepare(1024), m_recvEndpoint,
                                    boost::bind(UdpConnection::doRead, this,
                                                boost::asio::placeholders::error,
                                                boost::asio::placeholders::bytes_transferred));
    }

    void UdpConnection::write(const network::Frame &frame)
    {
        if (!m_socket.is_open())
            throw std::runtime_error("socket not opened");
        m_socket.get_io_service().post(boost::bind(UdpConnection::doWrite, this, frame));
    }

    void UdpConnection::write(const char *data, std::size_t len, const udp::endpoint &endpoint)
    {
        write({data, len, endpoint});
    }

    void UdpConnection::setOnMessageReceived(std::function<void(const Frame &frame)> frame)
    {
        m_onMessageReceived = frame;
    }

    void UdpConnection::doWrite(const Frame &frame)
    {
        m_socket.send_to(boost::asio::buffer(frame.data, frame.len), frame.endpoint);
    }

    void UdpConnection::doRead(const boost::system::error_code &errorCode, std::size_t len)
    {
        if (errorCode) {
            std::cerr << "UdpConnection::do_read() error = " << ec << std::endl;
            return;
        }

        const char *data = boost::asio::buffer_cast<const char *>(m_recvData.data());
        m_recvData.consume(len);

        read();

        if (m_onMessageReceived)
            m_onMessageReceived({data, len, m_recvEndpoint});
    }
}// namespace sfge::network