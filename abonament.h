//
// Created by Simona on 4/13/2022.
//

#ifndef OOP_ABONAMENT_H
#define OOP_ABONAMENT_H


#include <ostream>
#include <iostream>
#include <vector>
#include "aplicatie.h"

class abonament : public aplicatie{
    int pret{20};
    int nr_discuri_primite{1};
public:
    abonament() = default;

    abonament(int pret, int nrDiscuriPrimite);

    virtual ~abonament();

    abonament(const abonament& other);

    abonament& operator=(const abonament &other) ;

    friend std::ostream &operator<<(std::ostream &os, const abonament &abonament);

    friend std::istream &operator>>(std::istream &is, abonament &abonament);

    int pret_abonament();

    virtual int getAbonament();

    virtual int getDiscuriPrimite();


};


#endif //OOP_ABONAMENT_H
