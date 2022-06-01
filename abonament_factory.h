//
// Created by Simona on 6/1/2022.
//

#ifndef OOP_ABONAMENT_FACTORY_H
#define OOP_ABONAMENT_FACTORY_H


#include "abonamente_reduse.h"

class abonament_factory {
public:
    static abonamente_reduse * newAbon(const std::string &alegere);
};


#endif //OOP_ABONAMENT_FACTORY_H
