#include <stdio.h>
#include <stdlib.h>

int main()
{
	long number;
	short modulo;
    printf("Insert Number:");
    scanf("%ld",&number);
    
    while(number > 0)
    {
    	modulo = number % 2;
    	printf("%d ",modulo);
    	if(modulo == 1)
    	{
    		number = (number-1)/2;
    	}
    	else
    	{
    		number = number/2;
    	}
    	
    }
    printf("\n");
    
}
