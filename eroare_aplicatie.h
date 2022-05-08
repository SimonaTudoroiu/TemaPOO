//
// Created by Simona on 5/8/2022.
//

#ifndef OOP_EROARE_APLICATIE_H
#define OOP_EROARE_APLICATIE_H

#include <iostream>
#include <exception>
class eroare_aplicatie : public std::runtime_error{
public:
    eroare_aplicatie(const std::string &arg);
};


#endif //OOP_EROARE_APLICATIE_H
