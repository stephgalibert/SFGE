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

cmake_minimum_required (VERSION 3.8)

set (TARGET "config_tests")
set (SRCS configglobal_tests.cpp configphysics_tests.cpp configrenderer_tests.cpp)

add_executable (${TARGET} ${SRCS})

target_link_libraries (${TARGET} PUBLIC ${PROJECT_NAME} "gmock" "gtest" "gmock_main")
# Inject SFGE private libraries into the test suite includes tree
target_include_directories(${TARGET} PRIVATE ${SFGE_PRIVATE_INCLUDES})

add_test(NAME ${TARGET} COMMAND "${TARGET}")