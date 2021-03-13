cmake_minimum_required(VERSION 3.0)

project(network)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.65 REQUIRED COMPONENTS system thread chrono date_time)

include_directories(include)

set(SRCS client.cpp
        server.cpp
        udp_connection.cpp)

add_definitions(-DNETWORK_EXPORTS)

add_library(network SHARED ${SRCS})
target_link_libraries(network boost_system boost_thread)
