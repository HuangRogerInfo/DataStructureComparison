#include <stdlib.h>
#include "StringArray.h"
#include <string.h>

StringArray* getIntersection(const StringArray* array1, const StringArray* array2){
    
  StringArray* A = createEmptyArray();

  for(int i = 0; i< arrayLength(array1); i++){
      for(int j = 0; j< arrayLength(array2); j++){
          if( strcmp(getElementInArray(array1, i), getElementInArray(array2, j))==0 ){
              insertInArray(A,getElementInArray(array1, i) );
          }
      }
  }
  return A;
}