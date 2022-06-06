#include <stdio.h>
#include <stdlib.h>

long fak(int number);

int main()
{
    int number,fakultät;
    printf("Insert number:");
    scanf("%d",&number);
    fakultät = fak(number);
    printf("Fakultät von %d ist %d\n",number,fakultät);
    
}

long fak(int number)
{
    long result;
    if(number > 1)
    {
        result = number*fak(number - 1);
    }
    else 
    {
        result = 1;
    }
    return result;
}
