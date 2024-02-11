
#include <stdio.h>
#include "my_mat.h"


int main(){
    char items[ITEMSNUM];
    int values[ITEMSNUM];
    int weights[ITEMSNUM] = {0};
    
    int result[ITEMSNUM];
    for(int i=0;i<ITEMSNUM;i++){
        scanf(" %c", &items[i]);
        scanf(" %d", &values[i]);
        scanf(" %d", &weights[i]);
    }
    
    printf("Maximum profit: %d\n", knapSack(weights, values, result));
    printf("Selected items:");
    for(size_t i=0;i<ITEMSNUM;i++){
        if(result[i] == TRUE){ 
            printf(" %c", items[i]);
        }
    }
    
    return 0;
}
