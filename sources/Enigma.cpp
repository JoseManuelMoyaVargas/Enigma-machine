//
//  Enigma.cpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Enigma.hpp"


    Enigma::Enigma(int sizeAlpha,int* alpha){
        sizeAlphabet=sizeAlpha;
        alphabet=alpha;
        rotorsAdded=0;
        turnRotor2=false;
    }
    Enigma::~Enigma(){
        for( int i = 0 ; i<numOfRotors;i++){
            delete arrayRotors[i];
        }
        alphabet=nullptr;
        refl=nullptr;
    }

    Enigma::Enigma(int * ro ,  int * re, int sizeAlphabet,int initialPositionRotor){
        alphabet =new int[sizeAlphabet];
        for(int i = 0 ; i<sizeAlphabet ; i++){
            alphabet[i]=i+1;
        }
        
        XXXrot = new Rotor(alphabet,ro,sizeAlphabet,initialPositionRotor);
        refl =new Reflector(re);
    }
    
    
    Enigma::Enigma(int numberOfRotors,int * arrayRo[],int initialPositionRotor[],int * arrayNumOfTurnOversPerRotor,int * numberThatTurnRotors[],int * re,int sizeAlph){
        
       sizeAlphabet=sizeAlph;
       numOfRotors=numberOfRotors;
       alphabet =new int[sizeAlphabet];
       for(int i = 0 ; i<sizeAlphabet ; i++){
           alphabet[i]=i+1;
       }
       refl =new Reflector(re);
       
       arrayRotors = new Rotor * [numberOfRotors];
       for( int i = 0; i < numberOfRotors; i ++ ){
           arrayRotors[i]=new Rotor(alphabet,arrayRo[i],sizeAlphabet,initialPositionRotor[i],arrayNumOfTurnOversPerRotor[i],numberThatTurnRotors[i]);
       }
    
      for(int i=0;i<numberOfRotors;i++){
          arrayRotors[i]->printRotor();
      }
      
       
   }
    
    int Enigma::XXXcipher (int value){
        XXXrot->turn();
        int firstCipher= XXXrot->cipher2(value);
        int reflection = refl->cipher(firstCipher);
       
        int finalResult = XXXrot->cipherAfterReflection(reflection);
     
        return finalResult;
    }


    void Enigma::setNumberOfRotors( int numbOfRotors){
        numOfRotors=numbOfRotors;
        arrayRotors= new Rotor * [numbOfRotors];
    }

    void Enigma::addRotor(Rotor * rot, int initialPosition){
        rot->setInitialPosition(initialPosition);
        arrayRotors[rotorsAdded]=rot;
        rotorsAdded++;
    }

        
    void Enigma::addReflector(Reflector *  re){
        refl=re;
    }


    void Enigma::printRotorsMachine(){
        cout<<"###############################################"<<endl;
        for( int i = 0;i<numOfRotors;i++){
            arrayRotors[i]->printRotor();
        }
        cout<<"###############################################"<<endl;
    }

    
    
int Enigma::testCipherWithNotch(int value){
        if(value<=0 && value>sizeAlphabet){
            return -1;
        }
        int temp1=0;
        int temp2=0;
        bool nextTurn1=false;
        if(arrayRotors[0]->getInitialPosition()==-1){
            nextTurn1=arrayRotors[0]->checkNotchAndTurn();
        }else{
            arrayRotors[0]->turn();
        }
       
        if((numOfRotors>1)&&(nextTurn1==true)){
            bool nextTurn2=false;
            if((arrayRotors[1]->getInitialPosition()==-1)){
                nextTurn2=arrayRotors[1]->checkNotchAndTurn();
            }else{
                arrayRotors[1]->turn();
            }
          
            turnRotor2=true;
            //if((numOfRotors>2)&&(nextTurn2==true)){
            if((numOfRotors>2)&&(nextTurn2==true)){
                arrayRotors[2]->turn();
            }

        }
        
        if((turnRotor2==false) && (numOfRotors>2) && (arrayRotors[1]->getInitialPosition()==-1)&& (arrayRotors[1]->checkNotch())){
            arrayRotors[1]->turn();
            arrayRotors[2]->turn();
            
        }
        
        int firstCipher= arrayRotors[0]->cipher2(value);
        
        temp1=firstCipher;
        for(int i=1;i<numOfRotors;i++){
            temp1=arrayRotors[i]->cipher2(temp1);
        }
       
        int reflection = refl->cipher(temp1);
        temp2=reflection;
          
        for(int i=numOfRotors-1;i>=0;i--){
            
            temp2=arrayRotors[i]->cipherAfterReflection(temp2);
            
        }
        turnRotor2=false;
        return temp2;
    
}
