# Installs box2d deps
sudo apt-get install xorg-dev libglu1-mesa-dev -y

# Installs box2d
git clone --depth 1 --branch v2.4.1 https://github.com/erincatto/box2d.git
cd box2d && mkdir build && cd build
cmake ../ && sudo make install && cd ../../