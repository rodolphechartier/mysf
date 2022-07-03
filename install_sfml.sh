#!/bin/bash

log() {
	echo -e "\033[1;33minstall_sfml\033[0m: [\033[1;34m$(date "+%T")\033[0m]"
}

SFML_REPO="https://www.sfml-dev.org/files" # SFML Repository
SFML_VERSION="SFML-2.5.1"                  # SFML's version
BUILD_DIR=build                            # SFML Building directory's name

echo `log` "Update and upgrade apt-get..."
sudo apt-get update ; sudo apt-get -y upgrade

# Dependencies:
echo `log` "Installing SFML's dependencies..." &&
    sudo apt-get install -y cmake &&
    sudo apt-get install -y libfreetype6-dev &&
    sudo apt-get install -y libjpeg-dev &&
    sudo apt-get install -y libudev-dev &&
    sudo apt-get install -y libx11-dev &&
    sudo apt-get install -y libxrandr-dev &&
    sudo apt-get install -y libxcb1-dev &&
    sudo apt-get install -y libx11-xcb-dev &&
    sudo apt-get install -y libxcb-randr0-dev &&
    sudo apt-get install -y libxcb-image0-dev &&
    sudo apt-get install -y libghc-opengl-dev &&
    sudo apt-get install -y libflac-dev &&
    sudo apt-get install -y libogg-dev &&
    sudo apt-get install -y libvorbis-dev &&
    sudo apt-get install -y libvorbisenc2 &&
    sudo apt-get install -y libvorbisfile3 &&
    sudo apt-get install -y libopenal-dev &&
    sudo apt-get install -y libpthread-stubs0-dev &&
    sudo apt-get install -y libpthreadpool-dev ||
    exit 1

echo `log` "Downloading SFML..." &&
    wget "$SFML_REPO/$SFML_VERSION-sources.zip" &&
    unzip $SFML_VERSION-sources.zip && cd $SFML_VERSION ||
    exit 1

echo `log` "Building SFML..." &&
    mkdir $BUILD_DIR && cd $BUILD_DIR &&
    cmake ../ && make ||
    exit 1

echo `log` "Installing SFML..." &&
    sudo make install ||
    exit 1

echo `log` "SFML installed"
