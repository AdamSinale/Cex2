
#include <stdio.h>
#include "my_mat.h"

int main(){
    int graph[SIZE][SIZE];
    int i,j;
    char function;

    while(function != 'D' && function != EOF){
        scanf(" %c", &function);
        switch(function){
            case 'A':
                getGraph(graph);
                break;
            case 'B':
                scanf("%d %d", &i, &j);
                printf("%s\n",isTherePath(i,j,graph) == TRUE ? "True" : "False");
                break;
            case 'C':
                scanf("%d %d", &i, &j);
                printf("%d\n",shortestPath(i,j,graph));
                break;
            default:
                break;
        }
    }
    return 0;
}
