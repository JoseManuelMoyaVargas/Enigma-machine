//
//  AuxiliarFunctions.hpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef AuxiliarFunctions_hpp
#define AuxiliarFunctions_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

int contentOf(int *array , int numberOfShifts, int valor,int sizeAlphabet);
int indexOf2(int *array,int value,int numberOfShifts,int sizeAlphabet);
int indexOf3(int *initialPositions,int value,int numberOfShifts,int sizeAlphabet);
int indexOfValueInOriginal(int *initialPositions,int value);


#endif /* AuxiliarFunctions_hpp */
