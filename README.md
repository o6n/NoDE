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
