//
// Created by Simona on 4/13/2022.
//

#ifndef OOP_ABONAMENT_STANDARD_H
#define OOP_ABONAMENT_STANDARD_H


#include "abonament.h"
#include "disc.h"
#include <vector>
#include <string>
class abonament_standard: public abonament{
    disc disc_standard;
public:
    abonament_standard() = default;

    abonament_standard(int pret, int nrDiscuriPrimite, const disc &discStandard);

    virtual ~abonament_standard();

    abonament_standard(const abonament_standard& other);

    abonament_standard& operator=(const abonament_standard& other);

    int pret_abonament();

    std::vector<std::string> facilitati();

    int getDiscuriPrimite();

};

#endif //OOP_ABONAMENT_STANDARD_H
