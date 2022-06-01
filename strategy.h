//
// Created by Simona on 5/31/2022.
//

#ifndef OOP_STRATEGY_H
#define OOP_STRATEGY_H
#include <iostream>
#include "disc.h"

//design pattern : strategy
class strategy {
public:
    virtual ~strategy();
    virtual std::string sortarea() =0;
};


#endif //OOP_STRATEGY_H
