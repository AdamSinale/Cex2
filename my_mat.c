
#include <stdio.h>
#include "my_mat.h"


void getGraph(int graph[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0;j<SIZE;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for(int a=1; a<SIZE; a++){
        for(int i=1;i<SIZE;i++){
            for(int j=1;j<SIZE;j++){
                if(i!=a && j!=a && j!=i){
                    if((graph[i][j]>graph[i][a]+graph[a][j] || graph[i][j]==0) && graph[i][a] != 0 && graph[a][j] != 0){
                        graph[i][j] = graph[i][a] + graph[a][j];
                    }
                }
            }
        }
    }
}
int isTherePath(int i, int j, int graph[][SIZE]){
    if(graph[i][j] > 0){ return TRUE; }
    return FALSE;
}
int shortestPath(int i, int j, int graph[][SIZE]){
    if(isTherePath(i,j,graph) == TRUE){ return graph[i][j]; }
    return -1;
}

void getItems(char items[],int values[],int weights[]){
    for(int i=0;i<ITEMSNUM;i++){
        scanf("%c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
}
