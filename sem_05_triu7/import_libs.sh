#!/bin/bash

LIU7ST_DIR=../sem_04_liu7st
DARRIU7_DIR=../sem_01_vector
WORK_DIR=$(pwd)



cp $DARRIU7_DIR/darriu7.h ./
cp $LIU7ST_DIR/liu7st.h ./



cd $LIU7ST_DIR

make libliu7st.a

cp ./libliu7st.a $WORK_DIR

make clean

cd $WORK_DIR


