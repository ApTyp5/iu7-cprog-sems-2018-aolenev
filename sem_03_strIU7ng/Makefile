OBJ := strIU7ng.create.o strIU7ng.free.o strIU7ng.len.o strIU7ng.split.o strIU7ng.replace.o strIU7ng.mult.o strIU7ng.reverse.o main.o
COMPIL := -std=c99 -Wall -Werror -pedantic
OBJ_TEST := strIU7ng.free.test.exe  strIU7ng.find.test.exe strIU7ng.reverse.test.exe strIU7ng.create.test.exe strIU7ng.concat.test.exe strIU7ng.split.test.exe 
CC := gcc

app.exe: $(OBJ)
	$(CC) $(COMPIL) -o $@ $^

test: $(OBJ_TEST)

strIU7ng.create.test.exe: strIU7ng.create.test.o strIU7ng.create.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.free.test.exe: strIU7ng.free.o strIU7ng.free.test.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.reverse.test.exe: strIU7ng.reverse.o strIU7ng.reverse.test.o strIU7ng.create.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.concat.test.exe: strIU7ng.concat.o strIU7ng.concat.test.o strIU7ng.create.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.find.test.exe: strIU7ng.find.o strIU7ng.find.test.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.split.test.exe: strIU7ng.split.o strIU7ng.split.test.o strIU7ng.create.o strIU7ng.len.o strIU7ng.free.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.mult.test.exe: strIU7ng.mult.o strIU7ng.mult.test.o strIU7ng.create.o strIU7ng.free.o
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.replace.test.exe: strIU7ng.replace.o strIU7ng.replace.test.o strIU7ng.find.o strIU7ng.create.o
	$(CC) $(COMPIL) -o $@ $^

%.o: %.c *.h
	$(CC) $(COMPIL) -c $<

clean:
	rm *.o
