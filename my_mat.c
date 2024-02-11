
#include <stdio.h>
#include "my_mat.h"


void getGraph(int graph[][SIZE]){
    for(size_t i=0; i<SIZE; i++){
        for(size_t j=0;j<SIZE;j++){
            scanf(" %d", &graph[i][j]);
        }
    }
    for(size_t a=0; a<SIZE; a++){
        for(size_t i=0;i<SIZE;i++){
            for(size_t j=0;j<SIZE;j++){
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

int knapSack(int weights[],int values[],int selected_bool[]){
    int table[ITEMSNUM][WEIGHT+1] = {{0}};
    for(size_t i=0;i<=WEIGHT;i++){
        if(weights[0]<=i){ 
            table[0][i]=values[0]; 
        } 
    }
    for(size_t j=1;j<ITEMSNUM;j++){
        for(size_t i=1;i<=WEIGHT;i++){
            if(weights[j] > i || table[j-1][i] > values[j] + table[j-1][i-weights[j]])
                table[j][i] = table[j-1][i];
            else{
                table[j][i] = values[j] + table[j-1][i-weights[j]];
            }
        }
    }
    int index = WEIGHT;
    for(size_t j=ITEMSNUM-1;j>0;j--){
        if(table[j][index] != table[j-1][index]){
            selected_bool[j]=1;
            index -= weights[j];
        }else{
            selected_bool[j]=0;
        }
    }
    selected_bool[0] = table[0][index]>0 ? 1 : 0;
    return table[ITEMSNUM-1][WEIGHT];
}
