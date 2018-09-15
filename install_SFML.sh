#!/bin/bash

log() {
	echo -e "[\033[1;34m$(date "+%D %T")\033[0m]"
}

BUILD_DIR=build
VERSION=2.5.0

echo `log` "Installing SFML..."

sudo apt-get update ; sudo apt-get -y upgrade
sudo apt-get install -y cmake

wget "https://www.sfml-dev.org/files/SFML-$VERSION-sources.zip" &&
unzip SFML-$VERSION-sources.zip && cd SFML-$VERSION &&
mkdir $BUILD_DIR && cd $BUILD_DIR || exit 1

# Dependencies:
sudo apt-get install -y libfreetype6-dev
sudo apt-get install -y libjpeg-dev
sudo apt-get install -y libudev-dev
sudo apt-get install -y libx11-dev
sudo apt-get install -y libxrandr-dev
sudo apt-get install -y libxcb1-dev
sudo apt-get install -y libx11-xcb-dev
sudo apt-get install -y libxcb-randr0-dev
sudo apt-get install -y libxcb-image0-dev
sudo apt-get install -y libghc-opengl-dev
sudo apt-get install -y libflac-dev
sudo apt-get install -y libogg-dev
sudo apt-get install -y libvorbis-dev
sudo apt-get install -y libvorbisenc2
sudo apt-get install -y libvorbisfile3
sudo apt-get install -y libopenal-dev
sudo apt-get install -y libpthread-stubs0-dev
sudo apt-get install -y libpthread-workqueue0-dev

cmake ../ && make && sudo make install || exit 1

echo `log` "SFML installed"
