//
// Created by Simona on 4/19/2022.
//

#define OOP_ABONAT_H


#include "abonament.h"
#include "disc.h"
#include "subscriptie.h"
#include "abonamente_disponibile.h"
#include "abonament_factory.h"
#include <memory>
#include <iostream>
class abonat {
    static int id_abonat;
    int id;
    int buget_lunar{25};
    std::shared_ptr<subscriptie> abon;
    std::string tip_abonament;
    std::string disc_dorit;
    abonament_factory af;
public:
    abonat() =default;

    abonat(int bugetLunar, const std::string &tipAbonament, const std::string &discDorit);

    abonat(int bugetLunar, const std::string &tipAbonament);

    ~abonat();

    friend std::ostream &operator<<(std::ostream &os, const abonat &abonat);

    friend std::istream &operator>>(std::istream &is, abonat &abonat);

    std::shared_ptr<subscriptie> getTipAbonament();

    bool poate_cumpara_abonamentul();

    static void incrementeaza_id_abonat();

    static int returneaza_id_abonat();

    std::string get_tip_abonament();

    void setTipAbonament( const std::string& tip_abonament_);

    bool poate_cumpara_abonamentul_2();

    void reducerea_abonamentului();
};


