#!/bin/sh

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

set -e

# Prepare build environment
mkdir build-sonar && cd build-sonar
cmake -DTESTS=ON -DDOCS=OFF ../
cd ../

# Wraps the compilation with the Build Wrapper to generate configuration (used
# later by the SonarScanner) into the "bw-output" folder
build-wrapper-linux-x86-64 --out-dir bw-output cmake --build build-sonar/ -j
# And finally run the SonarCloud analysis - read the "sonar-project.properties"
# file to see the specific configuration
sonar-scanner -Dsonar.cfamily.build-wrapper-output=bw-output
