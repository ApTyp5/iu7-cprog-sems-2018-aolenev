#!/bin/bash

LIU7ST_DIR=../sem_04_liu7st
WORK_DIR=$(pwd)

cd $LIU7ST_DIR

make libliu7st.a

cp ./libliu7st.a $WORK_DIR

make clean

cd $WORK_DIR


