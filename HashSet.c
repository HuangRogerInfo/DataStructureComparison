#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Set.h"

typedef struct node_t
{
    char* elem;
    struct node_t* next;
}Node;

typedef struct liste_t
{
    Node* head;        
    size_t lengthList;  
}liste;

struct set_t{
    int lengthSet;      //la taille du tableau de liste
    int nb_element;
    liste* tab;         //tableau de liste
};

/**********************************************************/

liste* creer_liste() {
  liste* l = (liste*) malloc(sizeof(liste));
  l->head = NULL;
  l->lengthList = 0;
  return l;
}

Set* createEmptySet(void){
    Set* res = (Set*) malloc(sizeof(Set));
    res->lengthSet = 100;
    res->tab = malloc(res->lengthSet * sizeof(liste));
    for(int i = 0; i<res->lengthSet; i++){
        res->tab[i] = *(creer_liste());
    }
    return res;
}

/**********************************************************/

void detruire_liste(liste* l) {
  while(l->head != NULL) {
    Node* tmp = l->head;
    l->head = l->head->next;
    free(tmp);
  }
  free(l);
}

void freeSet(Set* set){
    for(int i = 0; i<set->lengthSet; i++ ){
        detruire_liste( &set->tab[i] );
    }
    free(set->tab);
    free(set);
}

/**********************************************************/

int fonctionHachage(const char* cle, int tailleTableau){
    int i;
    int retour = 0;
    int longueur = strlen(cle);
    for(i=0; i<longueur;i++){
        retour += cle[i] * 26^(i+1) ; 
    }

    if (retour<0){retour = -retour;}
    retour = retour % (tailleTableau);
    return retour;
}

/**********************************************************/

insert_t insertInSet(Set* set, char* element)
{   
    if(contains(set, element))
        return OLD;
    
    // si le nombre d'éléments de l'ensemble dépasse de 100 fois la taille du tableau de liste, alors on
    // multiplie par 10 ce tableau de liste
    if(set->nb_element++ > 100 * set->lengthSet){
        
        //on crée un nouveau tableau de liste mais redimensionné
        liste *tab2 = malloc(set->lengthSet*10 *sizeof(liste));

        for(int j = 0; j< set->lengthSet*10; j++){
            tab2[j] = *(creer_liste());
        }

        //on réaffecte tous les éléments des anciennes listes dans le nouveau tableau avec la fonction de hachage 
        //adéquate en prenant soin de libérer la mémoire prise par l'ancien tableau
        for(int i = 0 ; i< set->lengthSet ;  i++){
            
            Node *tmp = set->tab[i].head;
            while(tmp!=NULL){
                int hache = fonctionHachage(tmp->elem, set->lengthSet*10);

                Node* newHead = (Node*) malloc(sizeof(Node));
                newHead->elem = tmp->elem;
                
                //Place the element at the start of the list
                newHead->next = tab2[hache].head;
                tab2[hache].head = newHead;
                tab2[hache].lengthList++;

                Node *tmp2 = tmp; 
                tmp= tmp->next;
                free(tmp2);
            }
        }
        
        free(set->tab);
        //le set a dans sa structure le pointeur vers le nouveau tableau 
        set->tab = tab2;
        set->lengthSet = set->lengthSet*10;
    }
    
     // If the element is not in the set, a new node must be created to hold it
    Node* newHead = (Node*) malloc(sizeof(Node));
    if(!newHead)
        return ALLOC_ERROR;

    int hache = fonctionHachage(element, set->lengthSet);
    
    newHead->elem = element;
    //Place the element at the start of the list
    newHead->next = set->tab[hache].head;
    set->tab[hache].head = newHead;
    set->tab[hache].lengthList++;
    set->nb_element++;
    return NEW;
}

/**********************************************************/

size_t sizeOfSet(const Set* set)
{
    return set->nb_element;
}

/**********************************************************/

bool contains(const Set* set, const char* element)
{
    int hache = fonctionHachage(element, set->lengthSet);
    Node* curNode = set->tab[hache].head;

    //Iterate through the list to find the element
    while(curNode != NULL)
    {
        if (strcmp(element, curNode->elem) == 0) //Same element
            return true;
        curNode = curNode->next;
    }
    return false;
}

/**********************************************************/

StringArray* setIntersection(const Set* set1, const Set* set2)
{
    StringArray* array = createEmptyArray();
    Node* curNode;

    for(int i = 0; i<set1->lengthSet; i++){
        curNode = set1->tab[i].head;
        while(curNode != NULL)
        {  
        if (contains(set2, curNode->elem))
        {
            if(!insertInArray(array, curNode->elem))
            {
                freeArray(array, false);
                return NULL;
            }
        }
        curNode = curNode->next;
        }
    }    
    return array;
}
