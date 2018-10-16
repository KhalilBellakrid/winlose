#!/usr/bin/env bash

PACKAGE_NAME=winlose
DEST=./nodejs-binding
CORE_BUILD=../lib-ledger-core-build

CORE_CPP_API=src/api

./djinni/src/run \
	--idl idl/winlose.djinni \
	--cpp-out $CORE_CPP_API \
	--cpp-namespace api \
	--node-out $DEST \
	--node-type-prefix NJS \
	--node-include-cpp ../src/api \
	--node-package $PACKAGE_NAME

