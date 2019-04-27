#!/usr/bin/env bash
mkdir -p deps

# install glui ==================================
if [ ! -d "deps/glui" ]; then
	git clone https://github.com/libglui/glui deps/glui
fi
cd deps/glui
make
sudo cp lib/libglui.a /usr/local/lib
sudo cp include/GL/glui.h /usr/local/include

