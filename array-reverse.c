#include <stdio.h>
#include <stdlib.h>

void main() {

    int array[] = {1,2,3,4,5,6,7,8,9,0};

    int i = 0;
    int j = 9;

    while(i<j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }

    int k = 0;

    do {
        printf("%d ",array[k]);
        k++;
    }while(k<10);
}