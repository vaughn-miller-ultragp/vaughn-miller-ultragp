#include <stdio.h>
#include <stdlib.h>

void takeInput(int *array, int length){
    int i, flag;
    for(i = 0; i < length; i++){
        printf("Address %d >", &array[i]);
        flag = 0;
        while(flag == 0){
            int input;
            scanf("%d", &input);
            if(input >= 0 && input <= 100){
                array[i] = input;
                flag = 1;
            }
            else printf("Try Again >");
        }
    }
}

void main() {
    int *inputArray;

    inputArray = NULL;

    int i, n;

    printf("Entries: ");

    scanf("%d", &n);

    inputArray = (int*)malloc(n * sizeof(int));

    takeInput(inputArray, n);

    printf("\n\r");

    printf("Array has values: ");
    for(i = 0; i < n; i++){
        printf("%d ", inputArray[i]);
    }

    free(inputArray);

    printf("\n\r");
}

