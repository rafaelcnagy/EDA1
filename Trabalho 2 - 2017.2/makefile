CFLAGS= -o bancoBPE -Wall -Wextra -Werror -Wpedantic
DEPS= avl.h
OBJ= main.o avl.o


%.o: %.c $(DEPS)
	gcc -c main.o avl.o $(CFLAGS)

main: $(OBJ)
	gcc main.c $(CFLAGS)



