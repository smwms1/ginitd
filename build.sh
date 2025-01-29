#!/bin/sh

BUILDDIR=builddir
ROOTDIR=$(pwd)

echo "Compiling opus..."
meson compile -C $BUILDDIR
