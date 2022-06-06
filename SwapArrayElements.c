#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[],int size);

int main()
{
   
    int array[] = {1,2,3,4};
    printf("%d %d %d %d\n",array[0],array[1],array[2],array[3]);
    array[0] ^= array[1];
    array[1] ^= array[0];
    array[0] ^= array[1];
    printf("%d %d %d %d\n",array[0],array[1],array[2],array[3]);
    
}
