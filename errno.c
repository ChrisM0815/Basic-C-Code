#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

/*errno.h is used to display what went wrong.
Output of the Program:
Value of errno: 2
Error opening file: No such file or directory
Invalid value 
Valid value
Log(2.000000) = 0.693147
Log(1.000000) = 0.000000
Log(0.000000) is out of range

Compile with gcc errno.c -lm
*/
extern int errno ;
void error();
void domainError();
void rangeError();

int main () 
{
    error();
    domainError();
    rangeError();
}
//This is the macro set by system calls and some library functions in the event of an error to indicate what went wrong.
void error()
{
   FILE *fp;
   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      fprintf(stderr, "Value of errno: %d\n", errno);//The Error numbert
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));//Strerror returns the explanation of a errornumber
   } else {
      fclose(fp);
   }
}

//This macro represents a domain error, which occurs if an input argument is outside the domain, over which the mathematical function is defined and errno is set to EDOM.
void domainError()
{
   double val;

   errno = 0;
   val = sqrt(-10);
   
   if(errno == EDOM) {
      printf("Invalid value \n");
   } else {
      printf("Valid value\n");
   }
   
   errno = 0;
   val = sqrt(10);
   
   if(errno == EDOM) {
      printf("Invalid value\n");
   } else {
      printf("Valid value\n");
   }
}
//This macro represents a range error, which occurs if an input argument is outside the range, over which the mathematical function is defined and errno is set to ERANGE.
void rangeError()
{
   double x;
   double value;

   x = 2.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }

   x = 1.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }
   
   x = 0.000000;
   value = log(x);
   
   if( errno == ERANGE ) {
      printf("Log(%f) is out of range\n", x);
   } else {
      printf("Log(%f) = %f\n", x, value);
   }
    
}
