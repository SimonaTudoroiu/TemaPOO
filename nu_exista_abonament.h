//
// Created by Simona on 5/8/2022.
//

#ifndef OOP_NU_EXISTA_ABONAMENT_H
#define OOP_NU_EXISTA_ABONAMENT_H


#include "eroare_aplicatie.h"
#include <iostream>
#include <exception>
class nu_exista_abonament : public eroare_aplicatie{
public:
    explicit nu_exista_abonament(const std::string &arg);
};


#endif //OOP_NU_EXISTA_ABONAMENT_H
