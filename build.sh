#!/bin/bash
BUILD_DIR=build

mkdir ${BUILD_DIR}
cd ${BUILD_DIR}
qmake ../src
make $1
make install
cd -
rm ${BUILD_DIR}