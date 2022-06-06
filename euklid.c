#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("Insert a Number: ");
    scanf("%d",&x);
    printf("Insert another number: ");
    scanf("%d",&y);
    printf("The biggest common denominator of the numbers %d and %d is: \n",x,y);
    
    while(x != y)
    {
        if(x > y)
            x=x-y;
        else
            y=y-x;
    }
    
    printf("%d\n",x);
    return 0;
}
