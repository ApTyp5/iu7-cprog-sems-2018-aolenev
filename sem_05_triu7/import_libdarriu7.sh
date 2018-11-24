#!/bin/bash

DARR_DIR=../sem_01_vector
WORK_DIR=$(pwd)

cd $DARR_DIR

make libdarriu7.a

cp ./libdarriu7.a $WORK_DIR

make clean

cd $WORK_DIR


