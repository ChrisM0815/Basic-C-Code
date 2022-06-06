#include <stdio.h>
#include <stdlib.h>

typedef struct object
{
    int value;
    struct object *next;
}obj;

//Prototypes
void printValue(obj *object);
void printList(obj *start);
void add(obj *start, int value);
void push(obj ** start, int value);
int pop(obj ** start);
int remove_last(obj * start);
int remove_by_index(obj ** start, int n);
int remove_by_value(obj ** start, int value);
void delete_list(obj *start);

//Start Main
int main()
{
    obj *no1,*no2,*no3;//Objecte initialisieren
    
    no1 = (obj *) malloc(sizeof(obj));//Den Objekten speicherplatz zuweisen
    no2 = (obj *) malloc(sizeof(obj));
    no3 = (obj *) malloc(sizeof(obj));
    
    no1->value = 420;//Werte zuweisen
    no2->value = 69;
    no3->value = 666;
    
    no1->next = no2;//Nachfolgendes Element festlegen
    no2->next = no3;
    no3->next = NULL;
    
    printList(no1);//Ausgeben der Liste
    
    int AddObjects = 3;//Anzahl der Objekte die noch hinzugefügt werden soll
    for(int i=0;i<AddObjects;i++)//Zusätzliche Werte werden eingelesen und vorne und hinten eingefügt
    {
        int value;
        printf("Wert eingeben:");
        scanf("%d",&value);
        add(no1,value);//Hinten anhängen
        push(&no1,value);//dafor einfügen
    }
    
    printList(no1);//Ausgeben derListe
    
    printf("Dieser Wert wurde entfernt: %d\n",pop(&no1));//Der erste werd der Liste wird entfernt
    printList(no1);//Ausgeben derListe
    printf("Dieser Wert wurde entfernt: %d\n",remove_last(no1));//Der letzte wert der Liste wird entfernt
    printList(no1);//Ausgeben derListe
    printf("Dieser Wert wurde entfernt: %d\n",remove_by_index(&no1,3));//Der  wert an position 3(4te Element) der Liste wird entfernt
    printList(no1);//Ausgeben derListe
    printf("Dieser Wert wurde entfernt: %d\n",remove_by_value(&no1,666));//Das Element mit dem Wert 666 wird entfernt
    printList(no1);//Ausgeben derListe
    delete_list(no1);//Löscht die liste
    printList(no1);//Ausgeben derListe
    printf("\n");
}//End Main

//Functions
void printValue(obj *object)//Gibt ein Element aus
{
    printf("%d",object->value);
}

void printList(obj *start)//Gibt alle Elemente der Liste aus
{
    printf("start->");
    do
    {
        printValue(start);
        start = start->next;
        printf("->");
    }while(start != NULL);
    printf("end\n");
}

void add(obj *start, int value) //Fügt element an das Ende der Liste an
{
    obj *current = start;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (obj *) malloc(sizeof(obj));
    current->next->value = value;
    current->next->next = NULL;
}

void push(obj **start, int value)//Fügt am anfang der Liste ein neues Element ein
{
    obj * new_node;
    new_node = (obj *) malloc(sizeof(obj));

    new_node->value = value;
    new_node->next = *start;
    *start = new_node;
}

int pop(obj ** start)//Entfernt das ersten Element der Liste und gibt dessen value zurück 
{
    int retval = -1;
    obj *next_node = NULL;

    if (*start == NULL) {
        return -1;
    }

    next_node = (*start)->next;
    retval = (*start)->value;
    free(*start);
    *start = next_node;

    return retval;
}

int remove_last(obj * start)//Entfernt das letzte Element der Liste und gibt dessen value zurück 
{
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (start->next == NULL) {
        retval = start->value;
        free(start);
        return retval;
    }

    /* get to the second to last node in the list */
    obj * current = start;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->value;
    free(current->next);
    current->next = NULL;
    return retval;

}

int remove_by_index(obj ** start, int n) 
{
    int i = 0;
    int retval = -1;
    obj * current = *start;
    obj * temp_node = NULL;

    if (n == 0) {
        return pop(start);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->value;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

int remove_by_value(obj ** start, int value)//Entfernt das Element in welchem ein bestimmter Wert gefunden wird
{
    obj *previous, *current;

    if (*start == NULL) {
        return -1;
    }

    if ((*start)->value == value) {
        return pop(start);
    }

    previous = current = (*start)->next;
    while (current) {
        if (current->value == value) {
            previous->next = current->next;
            free(current);
            return value;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void delete_list(obj *start)//löscht die Liste
{
    obj  *current = start, 
            *next = start;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}
