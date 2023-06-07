pushd %~dp0..\..\build
Tests.exe --gtest_filter='Audio.*'
popd
