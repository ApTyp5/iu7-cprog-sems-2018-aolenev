#!/bin/bash

for Test in *.test.exe
do
    echo -e "\033[0;36m------------> Test './$Test'\033[0m\n <------------------"
    ./$Test
done
