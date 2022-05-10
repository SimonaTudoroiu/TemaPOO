//
// Created by Simona on 4/18/2022.
//

#ifndef OOP_ABONAMENT_PREMIUM_H
#define OOP_ABONAMENT_PREMIUM_H


#include "abonament.h"
#include "disc.h"
#include <vector>
#include <string>

class abonament_premium: public abonament {
    std::vector<disc> discuri_premium;
    int reducere_lunara;
public:
    abonament_premium() = default;

    abonament_premium(int pret, int nrDiscuriPrimite, const std::vector<disc> &discuriPremium, int reducereLunara);

    virtual ~abonament_premium();

    abonament_premium(const abonament_premium& other);

    abonament_premium& operator=(const abonament_premium& other);

    int pret_abonament() override;

    std::vector<std::string> facilitati() override;

    int getDiscuriPrimite() override;

    int disc_cu_reducere(disc d);

    void interogare_discuri_primite();
};


#endif //OOP_ABONAMENT_PREMIUM_H
