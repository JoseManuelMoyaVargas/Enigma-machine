//
//  AuxiliarFunctions.cpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "AuxiliarFunctions.hpp"


int contentOf(int *array , int numberOfShifts, int valor,int sizeAlphabet){
    int index = valor -1;
    int result =  array[(index+numberOfShifts)%sizeAlphabet];
    return result;
}
int indexOfValueInOriginal(int *initialPositions,int value){
    
    return initialPositions[value-1];
}


int indexOf2(int *array,int value,int numberOfShifts,int sizeAlphabet){
    int index=0;
  
    index=value-1;
   
    index = index -numberOfShifts;
    if(index<0){
        index=sizeAlphabet + index;
    }

    return index;
}


int indexOf3(int *initialPositions,int value,int numberOfShifts,int sizeAlphabet){
    int index=0;
    
    index=initialPositions[value-1];
    
    index = index -numberOfShifts;
    if(index<0){
        index=sizeAlphabet + index;
    }
    return index;
}

