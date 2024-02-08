
#include <stdio.h>
#include "my_mat.h"


int main(){
    char items[ITEMSNUM];
    int values[ITEMSNUM];
    int weights[ITEMSNUM];
    
    int result[ITEMSNUM];
    getItems(items, values, weights);
    printf("Maximum profit: %d\n", knapSack(weights, values, result));
    printf("Selected items:");
    for(int i=0;i<ITEMSNUM;i++){
        if(result[i] == TRUE){ 
            printf(" %c", items[i]);
        }
    }
    printf("\n");
    
    return 0;
}
