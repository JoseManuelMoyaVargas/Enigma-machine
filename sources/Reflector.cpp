//
//  Reflector.cpp
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Reflector.hpp"

int Reflector::cipher(int value){
    return refle[value-1];
}
Reflector::~Reflector(){
    refle=nullptr;
}
