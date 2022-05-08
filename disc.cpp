//
// Created by Simona on 4/12/2022.
//

#include "disc.h"
#include <vector>
#include <iostream>

disc::disc(const std::string &nume_disc_, int an_aparitie_, int nr_vanzari_lunar_, int pret_, const std::vector <piesa> &piese_) : nume_disc{nume_disc_}, an_aparitie{an_aparitie_}, nr_vanzari_lunar{nr_vanzari_lunar_}, pret{pret_}, piese{piese_}{}

std::ostream &operator<<(std::ostream &os, const disc &d) {
    os<<"Numele discului: "<<d.nume_disc<<", anul aparitiei: "<<d.an_aparitie<<", numarul de vanzari ale discului: "<<d.nr_vanzari_lunar<<", pretul discului: "<<d.pret<<"."<<std::endl;
    os<<"Piesele aparute pe discul "<<d.nume_disc<<" sunt:";
    for(unsigned long long i=0; i<d.piese.size();i++)
        os<<d.piese[i]<<" ";
    return os;
}

const std::string &disc::getNumeDisc() { return nume_disc;}

int disc::getPret() { return pret;}

bool disc::piese_in_disc(std::vector <std::string> piesele) {
    unsigned long long k=0;
    for(unsigned long long i=0;i<piesele.size();i++)
    {
        int ok=0;
        for(unsigned long long j=0;j<piese.size();j++)
            if(piesele[i]==piese[j].getNumePiesa())
                ok=1;
        if(ok==1)
            k++;
    }
    if(k==piesele.size())
        return true;
    else
        return false;
}

void disc::afisare_discuri_aparute_in_anul_n(int an_) {
    if (an_==an_aparitie)
        std::cout<<nume_disc<<" ";
}

void disc::gestionare_piese_dupa_anul_discului(int an_) {
    if(an_==an_aparitie)
        for(unsigned long long i=0;i<piese.size();i++)
            std::cout<<piese[i]<<std::endl;
}

int disc::profit_lunar() {
    int profit;
    profit=nr_vanzari_lunar*pret;
    return profit;
}
