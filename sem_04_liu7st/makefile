KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm

OBJ := liu7st.create.o
OBJ += liu7st.free.o
OBJ += liu7st.insert.o
OBJ += liu7st.remove.o
OBJ += liu7st.append.o
OBJ += liu7st.concat.o
OBJ += liu7st.has_cycle.o
OBJ += liu7st.revert.o
OBJ += liu7st.sort.o
OBJ += liu7st.set.o
OBJ += liu7st.get.o
OBJ += liu7st.iterator.o
OBJ += liu7st.check.o
OBJ += liu7st.print.o
OBJ += liu7st.apply.o

TEST_OBJ := liu7st.create.test.exe
TEST_OBJ += liu7st.free.test.exe
TEST_OBJ += liu7st.insert.test.exe
TEST_OBJ += liu7st.remove.test.exe
TEST_OBJ += liu7st.append.test.exe 
TEST_OBJ += liu7st.concat.test.exe
TEST_OBJ += liu7st.has_cycle.test.exe
TEST_OBJ += liu7st.revert.test.exe
TEST_OBJ += liu7st.sort.test.exe
TEST_OBJ += liu7st.set.test.exe
TEST_OBJ += liu7st.get.test.exe
TEST_OBJ += liu7st.iterator.test.exe
TEST_OBJ += liu7st.check.test.exe
TEST_OBJ += liu7st.print.test.exe
TEST_OBJ += liu7st.apply.test.exe

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c *.h
	$(CC) $(KEYS) -c $^

app.exe: $(OBJ) main.o
	$(CC) -o app.exe $^

test.exe: $(TEST_OBJ)

%.test.exe: $(OBJ) %.test.o
	$(CC) -o $@ $^

clean:
	$(RM) *.o *.exe *.gch
