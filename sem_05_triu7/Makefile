CC := gcc
CFLAGS := -Wall -Werror

CURDIR := ../sem_05_triu7
LIU7STDIR := ../sem_04_li7st
DARRIU7 := ../sem_01_vector/darriu7.h




all: app.exe
    ./app.exe
    
app.exe: $(OBJ) import_darriu7 import_liu7
    $(CC) -o $@ $^
    

import_darriu7:
	cp $(DARRIU7) ./

import_liu7:
	import_liu7.sh
    
%.o: %.c
    $(CC) -c $<
    



    
