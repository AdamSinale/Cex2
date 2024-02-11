
#ifndef MY_MAT_H
#define MY_MAT_H

    #define TRUE 1
    #define FALSE 0

    #define SIZE 10

    #define WEIGHT 20
    #define ITEMSNUM 5

    /* will create a new graph by the user's input*/
    void getGraph(int graph[][SIZE]);
    /* will return true if there is a path */ 
    int isTherePath(int i, int j,int graph[][SIZE]);
    /* will return the shortest path from i to j*/ 
    int shortestPath(int i, int j,int graph[][SIZE]);

    /* will return the best items to put in the backpack*/
    int knapSack(int weights[],int values[],int selected_bool[]);
#endif
