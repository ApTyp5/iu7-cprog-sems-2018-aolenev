%.o: %.c %.h
	gcc -c $^ 

all: matrix*.c sem02.c
	gcc -o matrix $^
