pushd %~dp0..\..\build
echo %cd%
Tests.exe --gtest_filter='Audio.*'
popd
