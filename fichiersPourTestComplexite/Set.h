/* ========================================================================= *
 * Set
 *
 * A generic Set interface for strings
 * ========================================================================= */

#ifndef _SET_H_
#define _SET_H_

#include <stddef.h>
#include <stdbool.h>
#include "StringArray.h"


/* Opaque Structure */
typedef struct set_t Set;

/* Enum for insertion */
typedef enum {NEW, OLD, ALLOC_ERROR} insert_t;

/* ------------------------------------------------------------------------- *
 * Create a new empty Set object.
 *
 * NOTE
 * The Set object must later be deleted by calling freeSet().
 *
 *
 * RETURN
 * Set      A new pointer to a Set object.
 * NULL     If an error occured.
 * ------------------------------------------------------------------------- */
Set* createEmptySet(void);

/* ------------------------------------------------------------------------- *
 * Free the allocated memory of the Set object $set$ but not its elements.
 *
 * PARAMETERS
 * set       A valid pointer to a set object
 * ------------------------------------------------------------------------- */
void freeSet(Set* set);


/* ------------------------------------------------------------------------- *
 * Return the number of elements in the Set $set$.
 *
 * PARAMETERS
 * set             A valid pointer to a set object
 *
 * RETURN
 * size_t          The number of elements
 * ------------------------------------------------------------------------- */
size_t sizeOfSet(const Set* set);


/* ------------------------------------------------------------------------- *
 * Insert a new element into the Set object $set$.
 *
 * NOTE
 * The function copies element adresses, and not the content !
 *
 * PARAMETERS
 * set             A valid pointer to a set object
 * element         A valid string to store in the set
 *
 * RETURN
 * NEW             If the element inserted is new to the set
 * OLD             If the element inserted was already in the set
 * ALLOC_ERROR     If an allocation error occured
 * ------------------------------------------------------------------------- */
insert_t insertInSet(Set* set, char* element);



/* ------------------------------------------------------------------------- *
 * Check whether an element exists in the Set $set$.
 *
 * PARAMETERS
 * set             A valid pointer to a set object
 * element         A valid string
 *
 * RETURN
 * true            If the element is in the set
 * false           Otherwise
 * ------------------------------------------------------------------------- */
bool contains(const Set* set, const char* element);



/* ------------------------------------------------------------------------- *
 * Computes the intersection of the given sets.
 *
 * NOTE
 * The Set object must later be deleted by calling freeSet().
 *
 * PARAMETERS
 * set1     A valid pointer to a set object
 * set2     A valid pointer to a set object
 *
 * RETURN
 * StringArray  A new pointer to a StringArray object holding the intersection
 * NULL         If an error occured.
 * ------------------------------------------------------------------------- */
StringArray* setIntersection(const Set* set1, const Set* set2);

void printSet(Set* unSet);

#endif // !_SET_H_
