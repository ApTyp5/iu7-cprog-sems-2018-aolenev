OBJ := strIU7ng.create.o strIU7ng.free.o strIU7ng.len.o strIU7ng.split.o strIU7ng.replace.o strIU7ng.mult.o strIU7ng.reverse.o main.o
COMPIL := -std=c99 -Wall -Werror -pedantic
CC := gcc

app.exe: $(OBJ)
	$(CC) $(COMPIL) -o $@ $^

%.o: %.c *.h
	$(CC) $(COMPIL) -c $<

clean:
	rm *.o
