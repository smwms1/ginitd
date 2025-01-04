#!/bin/sh

BUILDDIR=builddir
ROOTDIR=$(pwd)

echo "Compiling ginitd..."
meson compile -C $BUILDDIR
