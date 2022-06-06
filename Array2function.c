#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[],int size);

int main()
{
    //initialisieren des arrays und zuweiseung von Speicher für ein element
    int *array;
    array = malloc(sizeof(int));

    printf("Wie viele Werte sollen eingelesen werden?:");
    int size;//Anzahl der Werte die im Array gespeichert werden sollen
    scanf("%d",&size);
    int loops = 0;
    while(loops < size)
    {
        array[loops] = loops;//Speichert im Array einen wert. kann beliebig ausgetauscht werden
        array = realloc(array,(loops+2)*sizeof(int));//Vergrößert Array um einen int(4Byte)
        loops = loops +1;
    }
    printArray(array,size);//Funktionsaufruf
    
}
    
void printArray(int arr[],int size)
{
    printf("Werte im Array:\n");
    //gibt die im Array gespeicherten Werte aus
    for(int j=0;j<size;j++)
    {
        printf("\nPos. %d:::Wert: %d",j,arr[j]);
    }
    printf("\n");
}
