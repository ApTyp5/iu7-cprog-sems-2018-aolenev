OBJ := strIU7ng.create.o strIU7ng.free.o strIU7ng.len.o strIU7ng.split.o strIU7ng.replace.o strIU7ng.mult.o strIU7ng.reverse.o main.o
COMPIL := -std=c99 -Wall -Werror -pedantic
CC := gcc

app.exe: $(OBJ)
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.create.test.exe: strIU7ng.create.test.c strIU7ng.create.c
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.free.test.exe: strIU7ng.free.c strIU7ng.free.test.c
	$(CC) $(COMPIL) -o $@ $^

strIU7ng.reverse.test.exe: strIU7ng.reverse.c strIU7ng.reverse.test.c strIU7ng.create.c
	$(CC) $(COMPIL) -o $@ $^

%.o: %.c *.h
	$(CC) $(COMPIL) -c $<

clean:
	rm *.o
