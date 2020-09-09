//
//  Rotor.cpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Rotor.hpp"
#include "AuxiliarFunctions.hpp"


Rotor::Rotor(){
    numberOfShifts=0;
}

Rotor::Rotor(int * alp , int * ro, int sizeAlpha,int initialPosition){
    numberOfShifts=initialPosition-1;
    sizeAlphabet=sizeAlpha;
    alphabet =alp;
    rot=ro;
}

Rotor::~Rotor(){
   
    alphabet=nullptr;
    rot=nullptr;
    iniPosElems=nullptr;
    numbersThatTurOver=nullptr;
    numbersThatNotch=nullptr;
    
}



Rotor::Rotor(int * alp ,int * ro,int sizeAlph,int initialPosition,int numOfNumbersThatTurn,int * numbersThatTurO):Rotor(alp,ro,sizeAlph,initialPosition){
    numOfNumbersThatTurnsOver=numOfNumbersThatTurn;
    numbersThatTurOver=numbersThatTurO;
}

Rotor::Rotor(int * alp , int * ro,int sizeAlph){
    alphabet=alp;
    rot=ro;
    sizeAlphabet=sizeAlph;
    numsTurnsAdded=0;
    int valueRotor=0;
   
    iniPosElems=new int[sizeAlphabet];
    for(int i=0;i<sizeAlphabet;i++){
        valueRotor=contentOf(rot,0,i+1,sizeAlphabet);
        iniPosElems[valueRotor-1]=i;
    }
    
}

int Rotor::binarySearch(int arr[], int first, int last, int num) const {
       if (first <= last) {
          int mid = (first + last)/2;
          if (arr[mid] == num)
             return mid ;
          if (arr[mid] > num)
             return binarySearch(arr, first, mid-1, num);
          if (arr[mid] > num)
             return binarySearch(arr, mid+1, last, num);
       }
       return -1;
}



void Rotor::turn(){
    initialPosition=-1;
    numberOfShifts++;
    if(numberOfShifts==sizeAlphabet){
        numberOfShifts=0;
    }
}

int Rotor::cipher2(int value){
    int first=contentOf(rot, numberOfShifts, value,sizeAlphabet);
    
    int index=indexOf2(alphabet, first,numberOfShifts,sizeAlphabet);
    return index+1;
}

int Rotor::cipherAfterReflection(int value){
     int first=contentOf(alphabet, numberOfShifts, value,sizeAlphabet);
    int index = indexOf3(iniPosElems, first,numberOfShifts,sizeAlphabet);
    return index+1;
}

void Rotor::setNumOfNumbersThatTurnOver(int numOfNumber){
    numOfNumbersThatTurnsOver=numOfNumber;
    numbersThatTurOver =(int *) malloc(sizeof(int)*numOfNumber);
    numbersThatNotch =(int *) malloc(sizeof(int)*numOfNumber);
}


void Rotor::addNumberThatTurnOver(int number){
    numbersThatTurOver[numsTurnsAdded]=number;
    int notch=number-1;
    if(notch==0){
        notch=sizeAlphabet;
    }
    numbersThatNotch[numsTurnsAdded]=notch;
    
    numsTurnsAdded++;
    
}

void Rotor::setInitialPosition( int initialPos){
    initialPosition=initialPos;
    numberOfShifts=initialPos-1;
}


Rotor::Rotor(const Rotor &obj){
    sizeAlphabet=obj.sizeAlphabet;
    numberOfShifts=obj.numberOfShifts;
    alphabet=obj.alphabet;
    rot=obj.rot;
    numOfNumbersThatTurnsOver=obj.numOfNumbersThatTurnsOver;
    numsTurnsAdded=obj.numsTurnsAdded;
    numbersThatTurOver=obj.numbersThatTurOver;
    numbersThatNotch=obj.numbersThatNotch;
    iniPosElems=obj.iniPosElems;
}

Rotor& Rotor::operator = (const Rotor &o)
{
    return *this;
}

bool Rotor::checkNotchAndTurn(){
    for( int i=0;i<numOfNumbersThatTurnsOver;i++){
 
        if(numbersThatNotch[i]==numberOfShifts+1){
            turn();
            return true;
        }
    }
    /*int num = numberOfShifts+1;
    int index = binarySearch(numbersThatNotch, 0, numOfNumbersThatTurnsOver, num);
    if(index!=-1){
        turn();
        return true;
    }*/
    turn();
    return false;
    
}

bool Rotor::checkNotch() const{
    for( int i=0;i<numOfNumbersThatTurnsOver;i++){
        if(numbersThatNotch[i]==numberOfShifts+1){
            return true;
        }
    }
 
    return false;
}

int Rotor::getInitialPosition () const {
    return initialPosition;
}



void Rotor::printRotor() const{
    cout<<"Rotor definition"<<endl;
    cout<<"{ ";
    
    for( int i = 0; i<sizeAlphabet;i++){
        cout<<rot[(i+numberOfShifts)%sizeAlphabet]<<" ";
    }
    cout<<"}"<<endl;
    cout<<"{ ";
    
    for( int i = 0; i<sizeAlphabet;i++){
        cout<<alphabet[(i+numberOfShifts)%sizeAlphabet]<<" ";
    }
    cout<<"}"<<endl;
    
    cout<<"Initial positions"<<endl;
    cout<<"{ ";
    for( int i = 0; i<sizeAlphabet;i++){
        cout<<iniPosElems[i]<<" ";
    }
    cout<<"}"<<endl;
    
    
    cout<<"Number of turnovers "<<numOfNumbersThatTurnsOver<<endl;
    cout<<"Elements that turnover the rotor --> ";
    for( int i =0;i<numOfNumbersThatTurnsOver;i++){
        cout<<numbersThatTurOver[i]<<" ";
    }
    cout<<"Elements that notch the rotor --> ";
    for( int i =0;i<numOfNumbersThatTurnsOver;i++){
        cout<<numbersThatNotch[i]<<" ";
    }
    
    cout<<endl<<endl<<endl;;
    
}



