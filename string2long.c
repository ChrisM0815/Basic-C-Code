#include <stdio.h>
#include <stdlib.h>

int main()
{
    char test[10] = "123Test";
    char *ptr;
    long number;

    number = strtol(test,&ptr,10);
    printf("%d\n",number);
    printf("%s",ptr);

}
