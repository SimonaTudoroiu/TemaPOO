//
// Created by Simona on 4/18/2022.
//

#include "abonament_premium.h"


abonament_premium::abonament_premium(int pret, int nrDiscuriPrimite, const std::vector<disc> &discuriPremium,
                                     int reducereLunara) : abonament(pret, nrDiscuriPrimite),
                                                           discuri_premium(discuriPremium),
                                                           reducere_lunara(reducereLunara) {}



abonament_premium::~abonament_premium() {

}

abonament_premium::abonament_premium(const abonament_premium &other) : abonament(other){
    for(unsigned long long i=0;i<discuri_premium.size();i++)
        discuri_premium[i] = other.discuri_premium[i];
    reducere_lunara = other.reducere_lunara;
}

abonament_premium& abonament_premium::operator=(const abonament_premium& other){
    abonament::operator=(other);
    for(unsigned long long i=0;i<discuri_premium.size();i++)
        discuri_premium[i] = other.discuri_premium[i];
    reducere_lunara = other.reducere_lunara;
    return *this;
}

int abonament_premium::pret_abonament() {
    return getAbonament();
}

std::vector<std::string> abonament_premium::facilitati() {
    return {"primirea discului lunii impreuna cu un disc selectat de dumneavoastra/al doilea cel mai popular disc", "primirea unei reduceri lunare la achizitionarea oricarui altui disc din magazinele noastre", "oprirea abonamentului oricand"};
}

int abonament_premium::getDiscuriPrimite() {
    return 2;
}

int abonament_premium::disc_cu_reducere(disc d) {
    int c = d.getPret();
    return c - reducere_lunara;
}

void abonament_premium::interogare_discuri_primite() {
    for(unsigned long long i = 0; i< discuri_premium.size();i++)
        std::cout<<discuri_premium[i]<<std::endl;
}



