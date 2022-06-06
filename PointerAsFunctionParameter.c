#include <stdio.h>
#include <stdlib.h>

void change_value(int *ptr);

int main()
{
int  num = 123;
int *ptr = &num;
printf("%d\n", *ptr);//Gibt 123 aus
change_value(ptr);
printf("%d\n",*ptr);//Gibt 42 aus
return 0;
}

void change_value(int *ptr)
{
*ptr = 42;
}
