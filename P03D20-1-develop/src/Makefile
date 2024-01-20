CC=gcc 
CFLAGS=-Werror -Wextra -Wall -std=c11 
 
all: graph 
 
graph: stack.a graph.c polish_notation.c input.c output.c
	$(CC) $(CFLAG) graph.c polish_notation.c input.c output.c -L. -lstack -o ../build/graph 
stack.a: polish_notation.o 
	ar rc libstack.a polish_notation.o 
	ranlib libstack.a 
polish_notation.o:
	$(CC) $(CFLAG) -c polish_notation.c 
clean: 
	rm -rf ../build/* 
	rm -rf *.o *.a
rebuild: clean all