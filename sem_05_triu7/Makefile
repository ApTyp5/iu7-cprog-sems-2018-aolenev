CC := gcc
FLAGS := -Wall -Werror

ifeq ($(mod),deb)
	FLAGS += -O0 -g3
endif

ifeq ($(mod),rel)
	FLEGS += -O3 -g0
endif

OBJ := triu7_create.o
OBJ += triu7_free.o
OBJ += triu7_add.o
OBJ += triu7_add_subtree.o
OBJ += triu7_has_cycle.o
OBJ += triu7_dat_apply.o
OBJ += triu7_leav_sort.o
OBJ += triu7_dat_test.o
OBJ += triu7_size.o
OBJ += triu7_depth.o
OBJ += triu7_ptrint.o


app.exe: $(OBJ) 
	$(CC) -o $@ $^
    

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

clean:
	rm *.o *.exe *.gch
    



    
