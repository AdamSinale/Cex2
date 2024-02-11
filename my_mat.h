#define N 10
#define bagSize 5
#define maxWeight 20

void FloydWarshall(int graph[][N], int m);
void insertMatrix(int arr[][N]);
int hasPath(int arr[][N],int i ,int j);
int max(int a, int b);
void getSelectedItems(char items[], int selected_bool[], char result[]);
void printItems(char arr[], int n);
int knapsack( int wt[], int val[], int selected_bool[]);

