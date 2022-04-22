#include <stdio.h>
#include <stdlib.h>

void main() {
    int arr[] = {0,9,1,5,4,7,3,8,2,6};
    int i,j;
    for(i = 0; i<9; i++ ) {
        for(j = 0; j<9; j++ ) {
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

            }
        }
    }

    for(i = 0; i<10; i++ ){
        printf("%d ",arr[i]);
    }
}