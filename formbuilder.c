#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This Program creates a random figure out of a given number of blocks 

int main()
{
    int r = 2, c;
    time_t t;
    srand((unsigned) time(&t));
    // Input of the number of blocks
    printf("How many Blocks do you want to use to build a structure?");
    scanf("%d",&c);
    
    
    int *arr = (int *)malloc(r * c * sizeof(int)); 
  
    int i, j, count = 0; 
    for (i = 0; i <  r; i++) //initializes the table with 0
      for (j = 0; j < c; j++) 
         *(arr + i*c + j) = 0; 
    
    for(int i = 1; i < c; i++)
    {
       int xory = c*(rand()%2);            //determines if x or y coord. is changed at random
       int invxory = (1+((xory/c)*(-1)))*c;// gives the complementary coord. to what has been choosen in xory
       int dadblock = rand()%i;            // when creating a new block this chooses a random already existing block which is modified to create the new block
       int modifier = ((-1)+(rand() % 2)*2);//can be either -1 or 1 this value is added to the choosen coordinate of the dadblock to form the new block 
       //printf("Block: %2d dad: %2d mod: %2d xory: %2d\n",i,dadblock,modifier,xory/c); //for debbuging
        *(arr + xory + i) = *(arr + xory + dadblock) + modifier;//Zuweisen von X oder Y zum neuen Block
        *(arr + invxory + i) = *(arr + invxory + dadblock);     //Zuweisen von Y oder X zum neuen Block
        
        for(int j = 0; j<i;j++)//checks if block with same coord. already exists and causes it to get values assigned again 
        {
            if(((*(arr + xory + j)) == *(arr + xory + i)) && ((*(arr + invxory + j)) == *(arr + invxory + i)))
            {
                    i = i - 1;
                    
                    break;
            }
        }
                                                   
    }
    printf("\n");
    // Output of the Koordinates as a table: first colum => Block 1; second colum => Block 2; etc.
    /*
    for(int i = 0; i< c;i++)
        printf("%2d ",i);
    
    printf("\n\n");
    for (i = 0; i <  r; i++)//Printing of the table
    {
        for (j = 0; j < c; j++)
        {
            printf("%2d ", *(arr + i*c + j));
        }
        printf("\n");
    }
    */
    //Code for displaying the structure 
    for(int i=0;i < c;i++)//Sorting the Blocks By their Y-Value in descending order
    {
         for(int j=0;j < c-1;j++)
         {
                if(*(arr + c + j) < *(arr + c + j +1))
                {
                    //Swapping the Y-Values
                    int temp = *(arr + c + j);
                    *(arr + c + j) = *(arr + c + j +1);
                    *(arr + c + j +1) = temp; 
                    //Swapping the X-Values
                    temp = *(arr + j);
                    *(arr + j) = *(arr + j +1);
                    *(arr + j +1) = temp; 
                }
                
         }
    }
    int xmin = *arr;//used to store the minimun X-Value out of all Blocks
    int xmax = xmin;
    for(int i=0;i < c;i++)//Sorting the Blocks with same Y-Value by their X-Value in Ascending order
    {
         for(int j=0;j < c-1;j++)
         {
                if((*(arr + j) > *(arr + j +1))&&(*(arr + c + j) == *(arr + c + j +1)))
                {
                    
                    //Swapping the Y-Values
                    int temp = *(arr + c + j);
                    *(arr + c + j) = *(arr + c + j +1);
                    *(arr + c + j +1) = temp; 
                    //Swapping the X-Values
                    temp = *(arr + j);
                    *(arr + j) = *(arr + j +1);
                    *(arr + j +1) = temp; 
                    
                }
                if(*(arr + j) < xmin)
                    xmin = *(arr + j);
                if(*(arr + j) > xmax)
                    xmax = *(arr + j);
         }
    }
    /*
    printf("The Blocks have the Coordinates: \n");
    for (i = 0; i <  r; i++)//Prints out the table
    {
        for (j = 0; j < c; j++)
        {
            printf("%2d ", *(arr + i*c + j));
        }
        printf("\n");
    }
    */
    // Prints out a graphic representation of the structure
    int ymax = *(arr + c); // stores the maximal Y-Value out of all Blocks
    int counter = 0;//Counts how many Blocks have been printed
    for(int k = xmin;k <= xmax;)
    {
        
        if(counter == c)
            break;
        
        if(*(arr + counter) == k)//a Block is printed
        {
            printf("O");
            counter = counter +1;
        }
        else//A whitespace is printed
        {
            printf(" ");
        }
        
        if(k == xmax)//print the next line 
        {
            printf("\n");
            k = xmin;
        }
        else
        {
            k = k + 1;
        }
        
    }
    printf("\n");
    
    return 0;
}

