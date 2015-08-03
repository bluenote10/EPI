#!/bin/bash

cd `dirname $0`
mkdir -p build
cd build

echo -e "\n *** running cmake"
cmake ..

echo -e "\n *** running make"
make

compiler_exit=$?
echo "  => compiler exit: $compiler_exit"

if [ "$compiler_exit" -eq 0 ]; then  # compile success
  echo -e "\n *** running test"
  #ctest --output-on-failure -V
  #ctest
  ./Test
  prog_exit=$?
  echo "  => Program exit: $prog_exit"
  exit $?
fi



