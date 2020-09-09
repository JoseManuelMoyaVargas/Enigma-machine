//
//  Reflector.hpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Reflector_hpp
#define Reflector_hpp

#include "AuxiliarFunctions.hpp"

class Reflector {
private:
    
    int * refle;
public:
    
    Reflector(int * ref){
        refle=ref;
    }
    ~Reflector();
    
    
    
    
    
    int cipher(int value);
    void printReflector();
    
};


#endif /* Reflector_hpp */
