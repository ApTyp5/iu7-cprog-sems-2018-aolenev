#!/bin/bash

LIU7STDIR=../sem_04_liu7st


cd $LIU7STDIR

make build

cd -

for obj in *.o
do
    cp $LIU7STDIR/$obj ./
done

cd $LIU7STDIR

make clean

cd -





