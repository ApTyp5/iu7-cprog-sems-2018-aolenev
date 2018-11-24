CC := gcc
CFLAGS := -Wall -Werror


ifeq ($(mod),deb)
	FLAGS += -O0 -g3 
endif

ifeq ($(mod),rel)
	FLEGS += -O3 -g0 -DNDEBUG
endif



OBJ := triu7.create.o
OBJ += triu7.free.o
OBJ += triu7.add.o
OBJ += triu7.has_cycle.o
OBJ += triu7.size.o
OBJ += triu7.print.o
OBJ += triu7.add_subtree.o
OBJ += triu7.apply.o
OBJ += triu7.depth.o



TESTS += triu7.free.test.exe
#TESTS += triu7.add.test.exe
TESTS += triu7.has_cycle.test.exe
TESTS += triu7.apply.test.exe
#TESTS += triu7.size.test.exe
#TESTS += triu7.depth.test.exe
TESTS += triu7.add_subtree.test.exe
TESTS += triu7.create.test.exe




app.exe: libliu7st.a libdarriu7.a $(OBJ) main.o
	$(CC) -o $@ $(OBJ) -L. -lli7st -ldarriu7

run_tests: biuld_tests
	./run_tests.sh

build_tests: libliu7st.a libdarriu7.a $(TESTS)

%.test.exe: $(OBJ) %.test.o
	$(CC) -o $@ $^ -L. -lliu7st -ldarriu7

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< 


libliu7st.a:
	./import_libliu7st.sh

libdarriu7.a:
	./import_libdarriu7.sh

clean:
	rm *.o *.exe *.gch *.a
    



    
