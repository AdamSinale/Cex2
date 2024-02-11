#include "stdio.h"
#include "my_mat.h"


int main(){
    int weights[bagSize];
    int values[bagSize];
    int selected_bool[bagSize];
    char items[20];
    char result[bagSize] = {0};
    
    //get inputs from the user

    for (int i = 0; i<bagSize; i++) {
        printf("Enter item's name: ");
        scanf(" %c", &items[i]);

        printf("Enter weight: ");
        scanf("%d", &weights[i]);

        printf("Enter value: ");
        scanf("%d", &values[i]);
    }
    
    //apply algorithem on given items and values
    int value = knapsack( weights,  values,  selected_bool);
    printf("Maximum profit: %d\n" , value);

    //print booleans - self check
    int arraySize = sizeof(selected_bool) / sizeof(selected_bool[0]); // Calculate the size of the array

    for(int i =  0; i < arraySize; i++) {
        printf("%d", selected_bool[i]);
    }

    //print items
    getSelectedItems(items, selected_bool, result);
    printf("\n[");
    int arrayLength = sizeof(result) / sizeof(result[0]); // Calculate the length of the array

    for(int i =  0; i < arrayLength; i++) {
        if (result[i+1] == 0) {
        printf("%c] ", result[i]); // if its the last item
        break; 
        }
        else {
            printf("%c, ", result[i]); // Prints each character individually
        }
    }


    return 0;
}