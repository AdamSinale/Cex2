CC=gcc
AR=ar
OBJECTS_MAIN=my_graph.o
OBJECTS_MAIN_KNAPSACK = myKnapsack.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g

all: my_graph_main myKnapsack_main

myKnapsack_main: $(OBJECTS_MAIN_KNAPSACK) $(OBJECTS_LIB)
	$(CC) -o  myKnapsack_main my_mat.o myKnapsack.o

my_graph_main: $(OBJECTS_MAIN) $(OBJECTS_LIB) 
	$(CC) -o  my_graph_main my_mat.o my_graph.o
	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

myKnapsack.o: my_mat.h myKnapsack.c
	$(CC) $(FLAGS) -c myKnapsack.c


clean:
	rm -f *.o *.a *.so my_graph_main myKnapsack_main