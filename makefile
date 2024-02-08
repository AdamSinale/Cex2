
CC = gcc
FLAGS = -Wall -g

AR = ar
OBJECTS_MAIN1 = my_graph.o
OBJECTS_MAIN2 = my_Knapsack.o
OBJECTS_FUNCTIONS = my_mat.o
HEADER = my_mat.h

all: my_graph my_Knapsack


my_mat.a: $(OBJECTS_FUNCTIONS)
	$(AR) rcs my_mat.a $^
	
my_graph: $(OBJECTS_MAIN1) my_mat.a
	$(CC) $(FLAGS) -o $@ $< my_mat.a
my_Knapsack: $(OBJECTS_MAIN2) my_mat.a
	$(CC) $(FLAGS) -o $@ $< my_mat.a

my_graph.o: my_graph.c $(HEADER)
	$(CC) $(FLAGS) -c my_graph.c
my_Knapsack.o: my_Knapsack.c $(HEADER)
	$(CC) $(FLAGS) -c my_Knapsack.c
my_mat.o: my_mat.c $(HEADER)
	$(CC) $(FLAGS) -fPIC -c my_mat.c

.PHONY: clean
clean:
	rm -f *.o *.so *.a mains maindloop maindrec
