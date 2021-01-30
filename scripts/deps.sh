#!/bin/sh

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

# Installs project deps
sudo apt-get -y install libsfml-dev