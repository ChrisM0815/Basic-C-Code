#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
In einem String soll ein beliebiger anderer String gesucht werden und anschließen ersetzt werden
*/
int main()
{
    
    char sstring[20] = {"abcdefgdefg"};//string in dem gesucht werden soll
    
//pointer auf die Stelle in sstring wo der gesuchte string das erste mal vorkommt.
    char *found;
    found = strstr(sstring,"de");
	printf("found: %s\n",found);
//findet zweites vorkommen	
	char *found2;
	found2 = strstr(found+2,"de");
	printf("found2: %s\n",found2);
//Zwei stellen von AA werden an die Stelle in der de gefunden Wurde kopiert
    strncpy(found2,"AA",2);
    printf("sstring: %s\n",sstring);

}
//Für einem Offset kann man folgendes verwenden strncpy(found + Offset,"AA",2);
