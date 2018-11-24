CC := gcc
CFL := -Wall -Werror



libdarriu7.a: darriu7.o
	ar cr $@ $^

%.o: %.c *.h
	$(CC) $(CFL) -c $<


clean:
	rm *.o *.a

