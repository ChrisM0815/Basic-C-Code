#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int safeinput();
int main()
{
    int number;
    if((number = safeinput())!= EXIT_FAILURE)
      printf("The number as int in main: %ld\n",number);
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
        printf("Wrong Input detected Retard!\n");//Beleidigt Person die nciht weiß, was eine Zahl ist
        return EXIT_FAILURE;//Beendet programm und gibt zurück das es nicht erfolgreich war
      }

  }
  if(INT_MAX <= (number = atoi(snumber))|| number < 0) //Wandelt den String in int um und überprüft ob die Zahl zu größ für int ist
  {
    printf("I can't take it. It's to big :)\n");//That's what she said
    return EXIT_FAILURE;
  }
  printf("The number as a string: %s\n",snumber);//Gibt den String der die Zahl beinhaltet aus
  //printf("The number as int: %ld\n",number);
  return number;

}
