#!/bin/sh
GREEN='\033[0;32m'
NS='\033[0m'

for file in ./*.test.exe;
do echo -e "\n\n$GREEN|_________________{$file}_________________|$NS"; $file;
done;
