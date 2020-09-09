//
//  Enigma.hpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Enigma_hpp
#define Enigma_hpp

#include "AuxiliarFunctions.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

class Enigma{
    
private:
    Rotor * XXXrot;
    Reflector * refl;
    int * alphabet;
    int sizeAlphabet;
    
    /*Second part: two rotors**/
    Rotor **arrayRotors;
    int numOfRotors;
    int rotorsAdded;
    
    bool turnRotor2;
    
    
public:
    
    Enigma(int * ro ,  int * re, int sizeAlphabet,int initialPositionRotor);
    
    Enigma(int numberOfRotors,int * arrayRo[],int initialPositionRotor[],int numberThatTurnRotors[],int * re,int sizeAlphabet);
    
    Enigma(int numberOfRotors,int * arrayRo[],int initialPositionRotor[],int * arrayNumOfTurnOversPerRotor,int * numberThatTurnRotors[],int * re,int sizeAlph);
    
    
    Enigma(int sizeAlpha,int * alpha);
    ~Enigma();

    
    int XXXcipher (int value);
    
    
    int testCipherWithNotch(int value);
    
    
    void setNumberOfRotors( int numbOfRotors);
    void addRotor(Rotor * rot, int initialPosition);
    
    
    void addReflector(Reflector *  re);
    
    void printRotorsMachine();
    
    

};

#endif /* Enigma_hpp */
