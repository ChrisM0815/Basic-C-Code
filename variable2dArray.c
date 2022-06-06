#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r = 7, c = 4;//can be entered at runtime 
    int *arr = (int *)malloc(r * c * sizeof(int)); 
  
    int i, j, count = 0; 
    for (i = 0; i <  r; i++) 
      for (j = 0; j < c; j++) 
         *(arr + i*c + j) = ++count; 
  
    for (i = 0; i <  r; i++)
    {
      
        for (j = 0; j < c; j++)
        {
            printf("%2d ", *(arr + i*c + j));
        }
        printf("\n");
    }
    
    free(array):
    return 0;
}
