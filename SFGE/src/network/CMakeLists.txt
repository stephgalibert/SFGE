#
# This file is part of SFGE.
# Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
#
# SFGE is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# SFGE is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with SFGE. If not, see <https://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.8)

# project(network)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.71 REQUIRED COMPONENTS system thread chrono date_time)

include_directories(include)

set(SRCS client.cpp
        server.cpp
        udpconnection.cpp)

# add_definitions(-DNETWORK_EXPORTS)

add_library(network SHARED ${SRCS})

target_link_libraries(network boost_system boost_thread)
