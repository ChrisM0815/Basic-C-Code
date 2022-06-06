#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*assert.h contains the function void assert(int expression);
 *this function can be used to make sure a variable confirms to a certain criteria.
 * if the expression is true nothing happends. If it's false an error is displayed on stderr and the program
 * will be aborted
*/
int main()
{
   int a;
   char str[50];
	 
   printf("Enter an integer value: ");
   scanf("%d", &a);
   assert(a >= 10);
   printf("Integer entered is %d\n", a);
    
   printf("Enter string: ");
   scanf("%s", str);
   assert(str != NULL);
   printf("String entered is: %s\n", str);
	
   return(0);
}
