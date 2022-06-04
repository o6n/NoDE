# NoDE
NO Desktop Environment

NoDE it's simple window manager based on Tinywm and it's a mix between Clarawm and Keywm.

NoDE just need Rofi program https://github.com/davatorium/rofi

Compile with gcc

## Depends

VOIDLINUX: libX11-devel

DEBIAN: libx11-dev

## Build
Install gcc package

	$ gcc -o nodewm nodewm.c -lX11

## Install

	$ su cp nodewm /usr/bin/nodewm
 
	$ su cp nodewm.desktop /usr/share/xsessions/nodewm.desktop

## Keyboard
Super_L + Delete -> Close window

Super_L + Up -> Window in the foreground

Super_L + F11 -> Full screen window

### Apps
Super_L + Return -> Run xterm

Super_L + Menu -> Run rofi -show drun

Super_L + Delete -> Run rofi -show window

Super_L + F12 -> Exit NoDE

### Windows
Super_L + Left -> Left half screen

Super_L + Right -> Right half screen

Super_L + F1 -> Window top left

Super_L + F2 -> Window top right

Super_L + F3 -> Window bottom left

Super_L + F4 -> Window bottom right

Super_L + F1 -> Window top left

Super_L + F2 -> Window top right
