//
//  Rotor.hpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Rotor_hpp
#define Rotor_hpp

#include <stdio.h>
#include "AuxiliarFunctions.hpp"

class Rotor{
private:
    int sizeAlphabet;
    int numberOfShifts;
    int initialPosition;
    
    int * alphabet;
    int * rot;
    
    /***/
    int * iniPosElems;
  
    /***/
    int numOfNumbersThatTurnsOver;
    int numsTurnsAdded;
    int * numbersThatTurOver;
    
    int * numbersThatNotch;
    
    
    /**Variables for test*/
 

public:
    Rotor();

    Rotor(int * alp , int * ro,int sizeAlph,int initialPosition);
    Rotor(int * alp ,int * ro,int sizeAlph,int initialPosition,int numOfNumbersThatTurn,int * numbersThatTurO);
    Rotor(int * alp , int * ro,int sizeAlph);
    Rotor(  const Rotor &obj);
    Rotor& operator = (const Rotor &o);
    ~Rotor();
    
    
    void turn();

    int cipher2(int value);
    int cipherAfterReflection(int value);
    
    int getInitialPosition()const;

    /**New version*/
    void setInitialPosition( int initialPosition);
    void setNumOfNumbersThatTurnOver(int numOfNumber);
    void addNumberThatTurnOver(int number);
    

    /**new functions for two rotors*/

    bool checkNotch() const;
    bool checkNotchAndTurn();
    
    int binarySearch(int arr[], int p, int r, int num) const;
    
    
    void printRotor() const;
    
   
 

};




#endif /* Rotor_hpp */
