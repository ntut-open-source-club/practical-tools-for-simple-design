pushd %~dp/../build
./Tests --gtest_filter='Audio.*'
popd

