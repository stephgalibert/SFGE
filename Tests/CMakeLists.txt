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

# Retrieve private headers from the SFGE library
get_target_property(SFGE_PRIVATE_INCLUDES ${PROJECT_NAME} INCLUDE_DIRECTORIES)

add_subdirectory("common")
add_subdirectory("components")

if (DEFINED ENV{CI})
    # No GPU on the CI, skip resources tests
    message("Skipping resources tests")
else ()
    message("with resources tests")
    add_subdirectory("resources")
endif()

add_subdirectory("config")