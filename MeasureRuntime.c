#include <stdio.h>
#include <time.h>   	// for time()
#include <unistd.h>

void testcode();
//function to find the execution time of a C program
int main()
{
	
    clock_t start, stop;
    printf("Starte Zeitmessung...\n");
    time_t begin = time(NULL);
    start=clock();
    
    
    //code to run here
    testcode();
    
    
    time_t end = time(NULL);
    stop=clock();
    printf("\nEnde Zeitmessung...\n");
    
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    printf("Vergangene Zeit: %d sec.\n",(end - begin));


    
}

void testcode()
{
    for(long i=0; i<65535;i++)
    {
        double num = 3.141*((i*i)/4);
        printf("%d: %.3f\n",i,num);
            
    }
    sleep(1);
}


