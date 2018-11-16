#!/bin/bash

LIU7STDIR=../sem_04_liu7st


cd $LIU7STDIR

make build

cd -

for obj in $LIU7STDIR/*.o
do
    cp $obj ./
done

cp $LIU7STDIR/liu7st.h ./

cd $LIU7STDIR

make clean

cd -





