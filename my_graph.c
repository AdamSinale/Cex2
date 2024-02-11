#include <stdio.h>
#include "my_mat.h"

int main(){
    int i,j;
    char choice;
    int arr[N][N]; 
    

    
    do {
    printf("A - function 1\n");
    printf("B - function 2\n");
    printf("C - function 3\n");
    printf("D - exit\n");
    scanf(" %c", &choice);
    switch (choice) {
        case 'A':
            insertMatrix(arr);
            FloydWarshall(arr, N);
            break;  
        case 'B':
            printf("enter two nodes\n");
            scanf("%d" , &i);
            scanf("%d" , &j);
            int asnwer = hasPath(arr, i ,j);
            if (asnwer == 0) {
                printf("False\n");
            }
            else {
                printf("True\n");
            }
            break;
        case 'C':
            printf("enter two nodes\n");
            scanf("%d" , &i);
            scanf("%d" , &j);
            int distance = hasPath(arr, i ,j);
            if (distance == 0) {
                printf("-1");
            }
            else {
                printf("The distance between the nodes is: %d\n" , distance);
            }
            break;
        case 'D':
            return -1;
        default:
            printf("invlaid input\n");  
        }
    }
    while (choice != 'D' || choice != EOF);

    return 0;
}