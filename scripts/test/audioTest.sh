#!/bin/bash

pushd "$(dirname "$0")/../../build"
./Tests --gtest_filter='Audio.*'
popd

