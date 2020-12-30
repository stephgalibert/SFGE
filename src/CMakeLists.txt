cmake_minimum_required (VERSION 3.8)

project ("RType2K21" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory ("SFGE")
add_subdirectory ("Client")
# add_subdirectory ("Server")
