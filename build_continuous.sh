#!/bin/bash

cd `dirname "$0"`
clear

while true; do
  ./build.sh
  #python test/misc.py

  change=$(inotifywait -r -e close_write,moved_to,create,modify . \
    --exclude 'build/|#.*' \
    2> /dev/null)

  # very short sleep to avoid "text file busy"
  sleep 0.01

  clear
  echo "changed: $change `date +%T`"
done
