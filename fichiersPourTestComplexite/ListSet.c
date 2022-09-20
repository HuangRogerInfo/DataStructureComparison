#include <stdlib.h>
#include <string.h>
#include<stdio.h>

#include "Set.h"

typedef struct node_t Node;
struct node_t
{
    char* elem;
    Node* next;
};

struct set_t
{
    Node* head;
    size_t length;
};

Set* createEmptySet()
{
    Set* dict = (Set*) malloc(sizeof(Set));
    if(!dict)
        return NULL;
    dict->head = NULL;
    dict->length = 0;
    return dict;
}

void freeSet(Set* set)
{
    Node* current = set->head;
    Node* tmp;
    //Free all the node
    while(current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;

    }
    //Free the gardian
    free(set);
}

insert_t insertInSet(Set* set, char* element)
{
    //if(contains(set, element))
    //    return OLD;

    // If the element is not in the set, a new node must be created to hold it
    Node* newHead = (Node*) malloc(sizeof(Node));
    if(!newHead)
        return ALLOC_ERROR;

    newHead->elem = element;
    //Place the element at the start of the list
    newHead->next = set->head;
    set->head = newHead;

    set->length++;
    return NEW;
}

size_t sizeOfSet(const Set* set)
{
    return set->length;
}

bool contains(const Set* set, const char* element)
{
    Node* curNode = set->head;
    //Iterate through the list to find the element
    while(curNode != NULL)
    {
        if (strcmp(element, curNode->elem) == 0) //Same element
            return true;
        curNode = curNode->next;
    }
    return false;
}

StringArray* setIntersection(const Set* set1, const Set* set2)
{
    StringArray* array = createEmptyArray();
    Node* curNode = set1->head;
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

    return array;
}

void printSet(Set* unSet){
    Node* tmp = malloc(sizeof(Node));
    tmp = unSet->head;
    for(int i = 0; i<unSet->length; i++){
        printf("%s\n",tmp->elem);
        tmp = tmp->next;
    }
    free(tmp);
}
