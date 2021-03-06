﻿#
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

project ("SFGE" LANGUAGES CXX VERSION 0.1.0 DESCRIPTION "Simple & Fast Game Engine Library")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (COVERAGE)
     set (CMAKE_BUILD_TYPE "Debug")
     include (CodeCoverage.cmake)
     set (CODE_COVERAGE_VERBOSE ON)
     append_coverage_compiler_flags()
        setup_target_for_coverage_gcovr_xml(
                NAME coverage
                EXECUTABLE ctest
                BASE_DIRECTORY .
                EXCLUDE "Sample" "Tests"
        )
endif()

add_subdirectory ("SFGE")
add_subdirectory ("Sample")

if (TESTS)
    enable_testing()
    add_subdirectory ("Tests")
endif ()

if (DOCS)
    find_package(Doxygen REQUIRED)
    add_custom_target(docs
            COMMAND "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Generating SFGE documentation...")
endif()
