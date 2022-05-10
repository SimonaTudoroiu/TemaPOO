//
// Created by Simona on 4/19/2022.
//

#ifndef OOP_ABONAT_H
#define OOP_ABONAT_H


#include "abonament.h"
#include "disc.h"
#include "aplicatie.h"
#include <memory>
#include <iostream>
class abonat {
    static int id_abonat;
    int buget_lunar{25};
    std::shared_ptr<aplicatie> abon;
    std::string tip_abonament;
    std::string disc_dorit;
public:
    abonat() =default;

    abonat(int bugetLunar, const std::string &tipAbonament, const std::string &discDorit);

    abonat(int bugetLunar, const std::string &tipAbonament);

    virtual ~abonat();

    friend std::ostream &operator<<(std::ostream &os, const abonat &abonat);

    friend std::istream &operator>>(std::istream &is, abonat &abonat);

    std::shared_ptr<aplicatie> getTipAbonament();

    bool poate_cumpara_abonamentul();

    static void incrementeaza_id_abonat();

    static int returneaza_id_abonat();

    std::string get_tip_abonament();

    void setTipAbonament( std::string tip_abonament_);

    bool poate_cumpara_abonamentul_2();
};

#endif //OOP_ABONAT_H
