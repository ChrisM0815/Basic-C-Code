#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//Is used to get information how float numbers are handeld

int main () 
{
   printf("The maximum value of float = %.10e\n", FLT_MAX);
   printf("The minimum value of float = %.10e\n", FLT_MIN);
   printf("The maximum value of double  = %.10e\n", DBL_MAX);
   printf("The minimum value of double = %.10e\n", DBL_MIN);
   printf("The maximum value of long double = %.10e\n", LDBL_MAX);
   printf("The minimum value of long double = %.10e\n", LDBL_MIN);
   
   
   printf("The rounding Mode is = %d\n", FLT_ROUNDS);
   /* Rounding Mode
    -1 − indeterminable
    0 − towards zero
    1 − to nearest
    2 − towards positive infinity
    3 − towards negative infinity
   */
   printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);
   
   //Other Macros are availlable 
    
}
