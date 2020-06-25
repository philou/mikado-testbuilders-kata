#!/bin/sh
while true; do
	./inotify-win.exe -r -e modify ./src
    ./commit.sh
done
