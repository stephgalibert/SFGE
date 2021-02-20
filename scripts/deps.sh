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

# Installs box2d deps
sudo apt-get -y install xorg-dev libglu1-mesa-dev

# Installs box2d
git clone --depth 1 --branch v2.4.1 https://github.com/erincatto/box2d.git
cd box2d && mkdir build && cd build && cmake ../ && sudo make install
cd ../../

# Installs entt
git clone --depth 1 --branch v3.6.0 https://github.com/skypjack/entt.git
echo "Copied 'src/entt' to '/usr/include'"
cd entt && sudo cp -r src/entt /usr/include
cd ../

# Installs spdlog
git clone --depth 1 --branch v1.8.2 https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON ../ && sudo make install
cd ../../

# GTests
echo "Installing Google Tests"
git clone --depth 1 --branch release-1.10.0 https://github.com/google/googletest.git
cd googletest/googletest/
cmake -DBUILD_SHARED_LIBS=ON
make
sudo cp -r lib/libgtest* /usr/lib
sudo cp -r include/gtest /usr/include
sudo ldconfig -v | grep "test"
cd ../../../

# Installs project deps
sudo apt-get -y install libsfml-dev
sudo apt-get -y install libboost-all-dev