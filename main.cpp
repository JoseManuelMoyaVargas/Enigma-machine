
#include "AuxiliarFunctions.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Enigma.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    int input;
    int sizeAlphabet,numberOfRotors,numberOfReflectors;
    int * alphabet;
    int numberOfTasks;
    
    string output="";
    
    Rotor * * arrayRotors;
    Reflector * * arrayReflectors;
    
    
    cin>>sizeAlphabet;
    alphabet= new int[sizeAlphabet];
    for(int i=0;i<sizeAlphabet;i++){
        alphabet[i]=i+1;
    }
    cin>>numberOfRotors;
    
    arrayRotors = (Rotor * *)malloc(sizeof(Rotor * )*numberOfRotors);
    
    int numOfNumbersThatTurn=0;
    int * rota;
    for( int i = 0 ; i < numberOfRotors ; i ++){
    
        rota = new int[sizeAlphabet];
        for( int j = 0; j < sizeAlphabet ; j++){
            cin>>input;
            rota[j]=input;
        }
        
        arrayRotors[i]=new Rotor(alphabet,rota,sizeAlphabet);
       
        cin>>numOfNumbersThatTurn;
        arrayRotors[i]->setNumOfNumbersThatTurnOver(numOfNumbersThatTurn);
        for(int j=0;j<numOfNumbersThatTurn;j++){
            cin>>input;
            arrayRotors[i]->addNumberThatTurnOver(input);
        }
        
    }
    
    cin>>numberOfReflectors;
    arrayReflectors = (Reflector * *)malloc(sizeof(Reflector * )*numberOfReflectors);//Done
    
    int * refle;
    for( int i = 0 ; i < numberOfReflectors ; i ++){
        
        refle=new int [sizeAlphabet];
        for( int j = 0; j < sizeAlphabet ; j++){
            cin>>input;
           
            refle[j]=input;
        }
        arrayReflectors[i]=new Reflector(refle);
        
    }
    
    cin>>numberOfTasks;
    int numOfRotorsMachine;
    int indexOfRotor;
    int initialPosRotor;
    int indexOfReflector;
    
    Rotor * newRotor;
    Enigma * enig;//done
    
   
    
    for( int i = 0 ; i <numberOfTasks; i++){
        enig = new Enigma(sizeAlphabet,alphabet);
        
        
        cin>>numOfRotorsMachine;
        enig->setNumberOfRotors(numOfRotorsMachine);
        for(int j=0;j<numOfRotorsMachine;j++){
           
            cin>>indexOfRotor;
            cin>>initialPosRotor;
            newRotor = new Rotor(*arrayRotors[indexOfRotor]);
            enig->addRotor(newRotor,initialPosRotor);
        }
        
        cin>>indexOfReflector;
        enig->addReflector(arrayReflectors[indexOfReflector]);
        
        
        while(cin>>input){
            if(input==0){
                output=output+"\n";
                break;
            }else{
                cout<<to_string(enig->testCipherWithNotch(input))<<endl;
                
            }
        }
        
        delete enig;
    
        
    }
    
    
    delete [] alphabet;
    delete [] rota;
    delete  [] refle;
    
    for(int i=0;i<numberOfRotors;i++){
        delete arrayRotors[i];
    }
    free(arrayRotors);
    for(int i=0;i<numberOfReflectors;i++){
        delete arrayReflectors[i];
    }
    free(arrayReflectors);
    
}

