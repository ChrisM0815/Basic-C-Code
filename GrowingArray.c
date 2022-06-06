#include <stdio.h>
#include <stdlib.h>
/*
Es soll ein Array erstellt werden das je nach bedarf größer werden kann
*/
int main()
{
    //initialisieren des arrays und zuweiseung von Speicher für ein element
    int *array;
    array = malloc(sizeof(int));


    char AddValue = 'y';//Zur überprüfung ob mehr Werte eingelesen werden sollen
    int loops = 0;//Zählt wie viele Werte dem Array hinzugefügt wurden
    while(AddValue  == 'y' || AddValue =='Y')
    {
        printf("Position %d Wert hinzufügen:",loops);
        scanf("%d",&array[loops]);//Liest Wert zum Speichern im Array ein
        array = realloc(array,(loops+2)*sizeof(int));//Vergrößert Array um einen int(4Byte)
        printf("Weiteren Wert hinzufügen?(y = yes):");
        getchar();//negiert newline;
        AddValue = getchar();//ließt ein ob weitere eingaben kommen sollen
        loops = loops + 1;
    }
    //gibt die im Array gespeicherten Werte aus
    for(int i=0;i<loops;i++)
    {
        printf("\nPos.%d:%d",i,array[i]);
    }
    printf("\n");
}
