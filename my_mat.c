#include "my_mat.h"
#include "stdio.h"


// to remember:
// make dynamic programing by so:
// take the original matrix - A0
// create matrix A1.
// compute: A1[i,j] = min(A0[i,j] , A0[i,1] + A0[1,j])
// and so on...
// overall function: A_K[i,j] = min (A_K-1[i,j] , A_K-1[i,k] + A_K-1[k,j])  


void FloydWarshall(int graph[][N], int m){
    int dist[N][N];
    

    //Initilize the solution matrix with the graph input
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < m ; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //update solution matrix 
    for(int k = 0 ;k<m ;k++){
        for (int i = 0; i<m; i++) {
            for(int j = 0; j<m;j++){
                if (dist[i][j] != 0 ) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}


void insertMatrix(int arr[][N]){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            scanf("%d" , &arr[i][j]);
        } 
    }
    printf("insertion finished. The matrix is ready.\n");
}

int hasPath(int arr[][N],int i ,int j){
    if (arr[i][j] != 0)
    {
       return arr[i][j];
    }
    else{
        return 0;
    }
}

int knapsack( int wt[], int val[], int selected_bool[])
{
   int i, w;
   int K[bagSize+1][maxWeight+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= bagSize; i++)
   {
       for (w = 0; w <= maxWeight; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   //mark boolean array
    int sz = maxWeight;
        for(int i = bagSize; i>0; i--){
            if (K[i][sz-1] != K[i-1][sz-1]) {
                selected_bool[i-1] = 1;    //--> flag 1 if item has selected
                sz = sz-wt[i-1];
            }
        }


   return K[bagSize][maxWeight];
}




void getSelectedItems(char items[], int selected_bool[], char result[]){
    int result_index = 0;
    for(int i = 0; i<bagSize; i++){
        if (selected_bool[i] == 1) {
            result[result_index] = items[i];
            result_index++;
        }
    }
    result[result_index] = '\0';
}

// void printItems(char arr[], int n){
//     int arraySize = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

//     for(int i =  0; i < arraySize; i++) {
//         printf("%d ", arr[i]);
//     }
// }

int max(int a , int b){
    return (a>b) ? a : b;
}