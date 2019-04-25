
output: trabalho.o list.o stack.o queue.o manager.o
	gcc -Wall -Wextra -Werror -Wpedantic trabalho.o list.o stack.o queue.o manager.o -o output

trabalho.o: trabalho.c
	gcc -Wall -Wextra -Werror -Wpedantic -c trabalho.c

list.o: list.c list.h
	gcc -Wall -Wextra -Werror -Wpedantic -c list.c

stack.o: stack.c stack.h
	gcc -Wall -Wextra -Werror -Wpedantic -c stack.c

queue.o: queue.c queue.h
	gcc -Wall -Wextra -Werror -Wpedantic -c queue.c

manager.o: manager.c manager.h
	gcc -Wall -Wextra -Werror -Wpedantic -c manager.c

clean:
	rm *.o output
