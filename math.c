#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void hugeValue();

int main()
{
    hugeValue();
    return(0);
}

void hugeValue()
{
    double result = 1/0.0;
    printf("%f\n", result);
    if (result == HUGE_VAL)
        puts("HUGE_VAL\n");   
}
