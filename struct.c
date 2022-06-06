#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struktur
typedef struct 
{
    char vname[20];
   	char nname[20];
   	long PLZ;
   	char ort[20];
   	int geburtsjahr;	
}ADRESSE;

//Zugriff und Verwendung
int main()
{
    //initialisieren alternativ struct adresse zuhause
    ADRESSE zuhause;
    
    // Strings ändern
    strcpy(zuhause.vname,"Christoph");
    strcpy(zuhause.nname,"Speiser");
    strcpy(zuhause.ort,"Musterstadt");
    
    //Variablen ändern
    zuhause.PLZ = 88888;
    zuhause.geburtsjahr = 1995;
    
    //Alles Zuweisen
    ADRESSE zuhause2 = {"Rudi","Völler",00000,"Leverkusen",1827};
    
    //Ausgabe
    printf("Name: %s %s \nWohnort: %ld %s \nGeburtsjahr: %d\n\n",zuhause.vname, zuhause.nname,zuhause.PLZ,zuhause.ort,zuhause.geburtsjahr);
    printf("Name: %s %s \nWohnort: %ld %s \nGeburtsjahr: %d\n\n",zuhause2.vname, zuhause2.nname,zuhause2.PLZ,zuhause2.ort,zuhause2.geburtsjahr);
    return EXIT_SUCCESS;
}
