CFLAGS= -lm -Wall -Wextra -Werror -Wpedantic

all: clean filacirc.o pilhaseq.o lista.o main.o
	gcc -g filacirc.o pilhaseq.o lista.o main.o -o bancoBPE $(CFLAGS)

filacirc.o:
	gcc -g -c filacirc.c $(CFLAGS)

pilhaseq.o:
	gcc -g -c pilhaseq.c $(CFLAGS)

lista.o:
	gcc -g -c lista.c $(CFLAGS)

main.o:
	gcc -g -c main.c $(CFLAGS)

clean:
	rm -rf *.o bancoBPE
