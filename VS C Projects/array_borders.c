#include <stdio.h>
#include <stdlib.h>

void create_borders(int *arr, int width, int height){
    int i;
    for(i = 0; i < width*height; i++){
        if(i < width || i >= (width * height) - width){
            arr[i] = 1;
        }
        else if(i % width == 0 || i % width == (width - 1)){
            arr[i] = 1;
        }
    }
}

void main(){
    
    int i, width, height;
    

    width = 1;
    height = 10;

    int *arr = calloc(width * height, sizeof(int));

    create_borders(arr, width, height);

    //dynamic array printing as a bonus
    for(i = 0; i < width * height; i++){
        printf("%d ", arr[i]);
        if(i % width == (width - 1)){
            printf("\n");
        }
    }
        
}