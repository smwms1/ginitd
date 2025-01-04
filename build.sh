#!/bin/sh

BUILDDIR=builddir
ROOTDIR=$(pwd)

# Actually build ginitd
if [ -z "${*##*-c*}" ]
then
	echo "Reconfiguring build system..."
	meson setup $BUILDDIR
fi

echo "Compiling ginitd..."
meson compile -C $BUILDDIR
