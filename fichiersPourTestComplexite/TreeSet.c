#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Set.h"

typedef struct Node_st {
    char* elem;
    struct Node_st *g;
    struct Node_st *d;
}Node;

struct set_t{
    Node* tree;
    size_t lenght;
};

/**********************************************************/

Set* createEmptySet(void){
    Set* dict = (Set*) malloc(sizeof(Set));
    if(!dict)
        return NULL;
    dict->tree = NULL;
    dict->lenght = 0;
    return dict;
}

/**********************************************************/

size_t sizeOfSet(const Set* set){
    return set->lenght;
}

/**********************************************************/

void freeTree(Node* unArbre){
    if(unArbre !=NULL){
        freeTree(unArbre->g);
        freeTree(unArbre->d);
        free(unArbre);
    }
}

void freeSet(Set* set){
    freeTree(set->tree);
    free(set);
}

/**********************************************************/

void insertTree(Node* newNode, Node** A) {
    if ( (*A) == NULL) {
        (*A) = newNode;
    }
    else {
        if( strcmp(newNode->elem, (*A)->elem) < 0 ) {
            insertTree(newNode, &((*A)->g));
        }
        else {
            insertTree(newNode, &((*A)->d));
        }
    }
}

insert_t insertInSet(Set* set, char* element){
    if(contains(set, element))
        return OLD;

    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode)
        return ALLOC_ERROR;
    newNode->elem = element;
    newNode->g = NULL;
    newNode->d = NULL;

    insertTree(newNode, &(set->tree) );
    set->lenght++;
    return NEW;
}

/**********************************************************/

bool containsInTree(const char * element, Node* A) {
	if (A == NULL) {
		return false;
	}
	if (strcmp(element,A->elem) == 0) {
		return true;
	}
    if (strcmp(element,A->elem) < 0) {
		return containsInTree(element, A->g);
	} 
	else {
		return containsInTree(element, A->d);
	}
}

bool contains(const Set* set, const char* element){
    return containsInTree(element, set->tree);
}

/**********************************************************/

void intersectionArbre(Node * Tree1, Node * Tree2, StringArray * array) {
    if(Tree2 == NULL){
        return;
    }

    if (Tree1 != NULL) {
        if(containsInTree(Tree1->elem, Tree2) ) {
            if(!insertInArray(array, Tree1->elem))
            {
                freeArray(array, false);
            }
        }
        intersectionArbre(Tree1->g, Tree2, array);
        intersectionArbre(Tree1->d, Tree2, array);
    }
}

StringArray* setIntersection(const Set* set1, const Set* set2){
    
    StringArray* array = createEmptyArray();
    intersectionArbre(set1->tree, set2->tree, array);
    return array;
}

/**********************************************************/

void printArbre(Node* unArbre){
    if(unArbre != NULL){
        printArbre(unArbre->g);
        printf("%s\n", unArbre->elem);
        printArbre(unArbre->d);
    }
}

void printSet(Set* unSet){
    printArbre(unSet->tree);
}

/**********************************************************/
