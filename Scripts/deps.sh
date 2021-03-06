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

if [ -z "${NO_SUDO}" ]; then
  alias sudo='sudo'
else
  alias sudo=''
fi

# Installs box2d deps
sudo apt-get -y install xorg-dev libglu1-mesa-dev

# Installs box2d
echo "--------- Installing box2d ---------"
git clone --depth 1 --branch v2.4.1 https://github.com/erincatto/box2d.git
cd box2d && mkdir build && cd build && cmake ../
make -j
sudo make install
cd ../../
sudo rm -rf box2d

# Installs entt
echo "--------- Installing entt ---------"
git clone --depth 1 --branch v3.6.0 https://github.com/skypjack/entt.git
cd entt && sudo cp -r src/entt /usr/include
cd ../
sudo rm -rf entt

# Installs spdlog
echo "--------- Installing spdlog ---------"
git clone --depth 1 --branch v1.8.2 https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON ../
make -j
sudo make install
cd ../../
sudo rm -rf spdlog

# GTests
echo "--------- Installing Google Tests ---------"
git clone --depth 1 --branch release-1.10.0 https://github.com/google/googletest.git
cd googletest/googlemock/
cmake -DBUILD_SHARED_LIBS=ON
make -j
sudo cp -r lib/libg* /usr/lib
sudo cp -r include/gmock /usr/include
cd ../
sudo cp -r googletest/include/gtest /usr/include
cd ../../
sudo rm -rf googletest

# Installs project deps
sudo apt-get -y install doxygen graphviz
sudo apt-get -y install libsfml-dev
sudo apt-get -y install libboost-all-dev
# sudo pip3 install pyOpenSSL cryptography
sudo pip3 install gcovr
