CC := gcc
FLAGS := -Wall -Werror

ifeq ($(mod),deb)
	FLAGS += -O0 -g3
endif

ifeq ($(mod),rel)
	FLEGS += -O3 -g0
endif

OBJ := triu7.create.o
OBJ += triu7.free.o
OBJ += triu7.add.o
OBJ += triu7.add_subtree.o
OBJ += triu7.has_cycle.o
OBJ += triu7.dat_apply.o
OBJ += triu7.leav_sort.o
OBJ += triu7.dat_test.o
OBJ += triu7.size.o
OBJ += triu7.depth.o
OBJ += triu7.print.o



app.exe: $(OBJ) libliu7st.a  
	$(CC) -o $@ $(OBJ) -L. -l$<

%.test.o: 

%.o: %.c *.h
	$(CC) -c $< $(FLAGS)

libliu7st.a:
	./import_libliu7st.sh

clean:
	rm *.o *.exe *.gch *.a
    



    
