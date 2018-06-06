#!/bin/bash

set -e

CONFIG=$1

if [ "$CONFIG" == "" ]; then
  echo "missing CONFIG env var"
  exit 1
fi

export CONFIG

pushd ../winlose-build
rm -r *

if [ "$CONFIG" == "Debug" ]; then
  cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 14 2015 Win64" ../winlose
  cmake --build . --config Debug
elif [ "$CONFIG" == "Release" ]; then
  cmake -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 14 2015 Win64" ../winlose
  cmake --build . --config Release
fi

cp src/$CONFIG/winlose.dll ../winlose/binding/build
cp src/$CONFIG/winlose.lib ../winlose/binding
popd

pushd binding

if [ -d build ]; then
  echo "cleaning build"
  rm -r build
fi

if [ "$CONFIG" == "Debug" ]; then
  node-gyp --debug configure --msvs_version=2015
  node-gyp --debug build
elif [ "$CONFIG" == "Release" ]; then
  node-gyp --release configure --msvs_version=2015
  node-gyp --release build
fi

popd
