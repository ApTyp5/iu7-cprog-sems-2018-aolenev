CC := gcc
CFL := -Wall -Werror

ifeq ($(mod),db)
	CFL += -O0 -g3
endif


libdarriu7.a: darriu7.o
	ar cr $@ $^

app.exe: darriu7.o main.o
	$(CC) $(CFL) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFL) -c $<


clean:
	$(RM) *.o *.a

