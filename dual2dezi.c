#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long dezi = 0;
    short loops = 0;
    short input;
    printf("Inser Binary number (little endian): ");
    while((input = getchar()-48) != -38)
    {
    	if(input != 1 && input != 0)
    	{
    		printf("Wrong Input detected in position %d: %d \n",loops+1,input);
    		dezi = 0;
    		break;
    	}
    	dezi = dezi + (input * pow(2,loops));
    	loops = loops + 1;
    }
    printf("dezimal number: %d \n",dezi);
    
}
