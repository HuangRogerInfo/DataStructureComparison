/* ========================================================================= *
 * StringArray.h
 *
 * A StringArray is a vector of strings (null terminated char array).
 * ========================================================================= */

#ifndef _STRING_ARRAY_H_
#define _STRING_ARRAY_H_

#include <stdbool.h>


/* Opaque structure */
typedef struct StringArray_t StringArray;


/* ------------------------------------------------------------------------- *
 * Create an empty StringArray object.
 *
 * NOTE
 * The StringArray object must later be deleted by calling freeArray().
 *
 * RETURN
 * Array            A new pointer to a StringArray object
 * NULL             If an error occured
 * ------------------------------------------------------------------------- */
StringArray* createEmptyArray(void);


/* ------------------------------------------------------------------------- *
 * Free the allocated memory of the StringArray object $array$. If the flag
 * $deleteElements$ is true, the function free() is called on each element.
 *
 * PARAMETERS
 * array            A valid pointer to a StringArray object
 * deleteElements   Call the function free() on each element contained in
 *                  $array$
 * ------------------------------------------------------------------------- */
void freeArray(StringArray* array, bool deleteElements);


/* ------------------------------------------------------------------------- *
 * insert the element $element$ in the StringArray $array$.
 *
 * PARAMETERS
 * array      A valid pointer to a StringArray object
 * element    A valid string to insert
 *
 * RETURN
 * true       If the element was inserted
 * false      If an error occured
 * ------------------------------------------------------------------------- */
bool insertInArray(StringArray* array, char* element);


/* ------------------------------------------------------------------------- *
 * Return the number of objects contained in the StringArray $array$.
 *
 * PARAMETERS
 * array      A valid pointer to a StringArray object
 *
 * RETURN
 * nbElems    The number of elements in the given array
 * ------------------------------------------------------------------------- */
size_t arrayLength(const StringArray* array);


/* ------------------------------------------------------------------------- *
 * Return the element at position $position$ from the StringArray $array$.
 *
 * PARAMETERS
 * array      A valid pointer to a StringArray object
 * position   The position of the element in the array (0 <= position < length)
 *
 * RETURN
 * string    A pointer to the string stored at position $position$
 * ------------------------------------------------------------------------- */
char* getElementInArray(const StringArray* array, size_t position);


/* ------------------------------------------------------------------------- *
 * Suffle the StringArray $array$ in place
 *
 * PARAMETERS
 * array      A valid pointer to a StringArray object
 * ------------------------------------------------------------------------- */
void shuffleArray(StringArray* array);

/* ------------------------------------------------------------------------- *
 * Return a new StringArray object that contains the common elements of the
 * two given StringArray objects.
 *
 * NOTE
 * The new StringArray object must later be deleted by calling
 * freeArray(array, false).
 * Note that the function copies adresses of common elements. It doesn't clone
 * the content of common elements.
 *
 * PARAMETERS
 * array1       A valid pointer to the first StringArray object
 * array2       A valid pointer to the second StringArray object
 *
 * RETURN
 * array        A new StringArray object that contains the common elements
 * NULL         if an error occured
 * ------------------------------------------------------------------------- */
StringArray* getIntersection(const StringArray* array1, const StringArray* array2);




#endif // !_STRING_ARRAY_H_
