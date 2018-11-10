CC := gcc
CFLAGS := -Wall -Werror




all: app.exe
    ./app.exe
    
app.exe: $(OBJ)
    $(CC) -o $@ $^
    
    
%.o: %.c
    $(CC) -c $<
    
    