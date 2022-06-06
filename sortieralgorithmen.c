#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

void printArray(int arr[],int size);
void swap(int arr[],int pos1,int pos2);
int arrayasc(int arr[],int start,int end);
int randomInt(int max);
int safeinput();
void bubblesort(int arr[],int size);
void selectionsort(int arr[],int size);
void insertionsort(int arr[],int size);
void quicksort(int array[],int size);
void flosssort(int arr[],int size);
void compactsort(int arr[],int lb, int rb);




int main()
{
    //initialisieren des arrays und zuweiseung von Speicher für ein element
    srand((unsigned) time(NULL));
    clock_t start, stop;
    int *array;
    array = malloc(sizeof(int));
    int size;//Anzahl der Werte die im Array gespeichert werden sollen
    int loops = 0;
    int maxnum;//maximale größe der Zahlen
    //Eingabe von Array Größe bzw. max größe der Zufallszahlen von 0 bis maxnum
    printf("Wie viele Zahlen sollen erzeugt werden?:\n");
    if((size = safeinput()) == EXIT_FAILURE)
    {
        exit(0);
    }
    printf("Wie groß sollen die Zahlen maximal sein?:\n");
    if((maxnum = safeinput()) == EXIT_FAILURE)
    {
        exit(0);
    }
    //Befüllen des Array mit Zufallszahlen Start
    while(loops < size)
    {
        array[loops] = randomInt(maxnum);//Speichert im Array einen wert. kann beliebig ausgetauscht werden
        loops = loops +1;
        array = realloc(array,(loops+1)*sizeof(int));//Vergrößert Array um einen int(4Byte)
    }
    //printArray(array,size);
    //Befüllen des Array mit Zufallszahlen Ende
    //Bubblesort
    start=clock();
    bubblesort(array,size);
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    //Selectionsort
    start=clock();
    selectionsort(array,size);
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    //Insertionsort
    start=clock();
    insertionsort(array,size);
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    //Quicksort WIP
    /*
    start=clock();
    quicksort(array,size);
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    */
    //Flosssort
    start=clock();
    flosssort(array,size);
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    //Compactsort
    start=clock();
    printf("\nCompactsort");
    int arr[size];
    for(int i=0;i<size;i++)//Kopie von dem Array anlegen, dass das orginalarray noch für andere Sortieralgorithmen verwendet werden kann
    {
        arr[i] = array[i];
    }
    compactsort(arr,0,size-1);
    printf("\nSorted by Compactsort\n");
    printf("%d",arrayasc(arr,0,size));
    stop=clock();
    fprintf(stderr,"CPU Laufzeit: %.10f sec.\n",(float) (stop-start)/CLOCKS_PER_SEC);
    
    //End of Program
    printf("\n");
    free(array);
}
    
void printArray(int arr[],int size)//gibt die im Array gespeicherten Werte aus
{
    printf("Werte im Array:");
    for(int j=0;j<size;j++)
    {
        printf("%3d ",arr[j]);
    }
    printf("\n");
}

void swap(int arr[],int pos1,int pos2)
{
    if(pos1 == pos2)
        return;
    else
    {
        arr[pos1] ^= arr[pos2];//Swapping 
        arr[pos2] ^= arr[pos1];
        arr[pos1] ^= arr[pos2];
    }
}

int randomInt(int max)//erzeugt eine Zufallszahl
{
    return((1 + rand() % max));
    //return(rand() % max);
}

int arrayasc(int arr[],int start,int end)//checks if a subarray from position start to position end is in ascending order(exmpl.: 2 4 5 6 7...)
{
    for(int i = start;i<end-1;i++)
    {
        if(arr[i]>arr[i+1])
            return i; // returns the position where the first pair of numbers is not ascending
        
    }
    return -1; //returns -1 if the complete array is in ascending order
}

int safeinput()
{

  char cnumber; //Variable für eingegebene Ziffern
  char *snumber; // Variable für Zahl als string
  int loops = 0; // Anzahl der Schleifendurchläufe -> Position im Sting an die die Zahl geschrieben werden soll
  int number;//Hier soll die Zahl als int gespeichert werden
  snumber = malloc(sizeof(char));//Weiß snumber Speicher für ein char zu
  printf("Insert number:");
  while((cnumber = getchar()) != '\n' && cnumber != EOF)//Eingabe der Ziffern + Enter beendet Eingabe
  {
      if(cnumber > 47 && cnumber < 58)//nur Zahlen von 0 bis 9 können eingegeben werden
      {
          strcpy(snumber + loops,&cnumber);//kopiert die eingelesen ziffer an position loops in den string
          loops = loops + 1;
          snumber = realloc(snumber,(loops +1)*sizeof(char));//Gibt snumber speicher für ein weiteren char
      }
      else//wenn flasche Eingabe entdeckt
      {
        printf("Wrong Input detected!\n");//Beleidigt Person die nciht weiß, was eine Zahl ist
        return EXIT_FAILURE;//Beendet programm und gibt zurück das es nicht erfolgreich war
      }

  }
  if(INT_MAX <= (number = atoi(snumber))|| number < 0) //Wandelt den String in int um und überprüft ob die Zahl zu größ für int ist
  {
    printf("I can't take it. It's to big :)\n");//That's what she said
    return EXIT_FAILURE;
  }

  return number;

}

void bubblesort(int array[],int size)
{
    int arr[size];
    for(int i=0;i<size;i++)//Kopie von dem Array anlegen, dass das orginalarray noch für andere Sortieralgorithmen verwendet werden kann
    {
        arr[i] = array[i];
    }
    printf("\nBubblesort\n");
    
    for(int i=0;i < size;i++)
    {
         for(int j=0;j < size-1;j++)
         {
                int temp;
                if(arr[j] > arr[j+1])
                {
                    
                    //printf("Swapping %d with %d \n",arr[j],arr[j+1]);
                    swap(arr,j,j+1);
                }
                
         }
    }
    printf("Sorted by Bubblesort\n");
    //printArray(arr,size);
    printf("%d",arrayasc(arr,0,size));
}

void selectionsort(int array[],int size)
{
    int min;
    int arr[size];
    
    for(int i=0;i<size;i++)
    {
        arr[i] = array[i];
    }
    
    printf("\nSelectionsort\n");
    for(int i=0;i < size-1;i++)
    {
        min = i; 
        for(int j=(i+1);j < size;j++)
         {
                if(arr[j] < arr[min])
                {
                    min = j;
                    
                }
         }
         //printf("Swapping %d with %d \n",arr[i],arr[min]);
         if(i != min)
         {
            //Swapping
            swap(arr,i,min);
         }
    }
    printf("Sorted by Selectionsort\n");
    //printArray(arr,size);
    printf("%d",arrayasc(arr,0,size));
}

void insertionsort(int array[],int size)
{
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i] = array[i];
    }

    printf("\nInsertionsort\n");
    for(int i=1;i<size;i++)
    {
        int key = arr[i];
        int j = i -1;
        while((j>=0) && (arr[j] > key))
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
    printf("Sorted by Insertionsort\n");
    //printArray(arr,size);
    printf("%d",arrayasc(arr,0,size));
}

void quicksort (int array[],int size)
{
    
}

void flosssort(int array[],int size)
{
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i] = array[i];
    }
    printf("\nFlosssort");
    int j = 0;//offset variable
    int swaped;
    do
    {
        swaped = 0;
        for(int i=j;i<(size-1);i=i+2)
        {
            if(arr[i]> arr[i+1])
            {
                swaped = 1;
                swap(arr,i,i+1);
                //printf("swapped %5d with %5d(%d<>%d) %d\n",arr[i+1],arr[i],i,i+1,j);
            }
        }
        
        j = j+1+(-2*j);//makes 1 out of 0 and 0 out of one
    
    }while(swaped == 1);
    printf("\nSorted by Flosssort\n");
    //printArray(arr,size);
    printf("%d",arrayasc(arr,0,size));
}

void compactsort(int arr[],int lb, int rb)
{
    if(lb >= rb)
    {
        return;
    }
    int min = lb,max = min;//set min and max to first value in the array
    for(int i = lb+1;i<=rb;i++)
    {
        if(arr[min] > arr[i])
            min = i;
        else if(arr[max] < arr[i])
            max = i;
    }
    if(lb == max)
    {
        swap(arr,min,max);
        swap(arr,min,rb);
        
    }
    else if(rb == min)
    {
        swap(arr,min,max);
        swap(arr,max,lb);
        
    }
    else
    {
        swap(arr,lb,min);
        swap(arr,rb,max);
        
    }
    compactsort(arr,lb+1,rb-1);
}
