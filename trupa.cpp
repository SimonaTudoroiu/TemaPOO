//
// Created by Simona on 4/12/2022.
//

#include "trupa.h"
#include <string>
#include <vector>
#include <iostream>

trupa::trupa(const std::string &nume_, const std::string &solist_, int an_infiintare_, const std::vector <disc> &discuri_) : nume{nume_}, solist{solist_}, an_infiintare{an_infiintare_}, discuri{discuri_}{}

trupa::trupa(const trupa &other) : nume{other.nume}, solist{other.solist}, an_infiintare{other.an_infiintare}, discuri{other.discuri}{}

trupa &trupa::operator=(const trupa &other) {
    nume = other.nume;
    solist = other.solist;
    an_infiintare = other.an_infiintare;
    discuri = other.discuri;
    return *this;
}

trupa::~trupa() {}

std::ostream &operator<<(std::ostream &os, trupa &tr) {
    os<<"Nume trupa: "<<tr.nume<<", an de infiintare al trupei: "<<tr.an_infiintare<<", solistul trupei: "<<tr.solist<<".";
    for (unsigned long long i = 0;i<tr.discuri.size();i++)
        os<<tr.discuri[i]<<' ';
    return os;
}

bool trupa::verificare_disc(std::vector <std::string> piesele) {
    for(unsigned long long i=0;i<discuri.size();i++)
        if(discuri[i].piese_in_disc(piesele)==true)
            return true;
    return false;

}

void trupa::clasificare_trupa() {
    int k=0;
    for(unsigned long long i=0; i<discuri.size();i++)
        k = k + discuri[i].profit_lunar()*12;
    if(k > 10000)
        std::cout<<"Trupa "<<nume<<" se afla printre trupele cu profitul cel mai mare provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<std::endl;
    else if(k> 5000)
        std::cout<<"Trupa "<<nume<<" se afla printre trupele cu profit mediu provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<std::endl;
    else
        std::cout<<"Trupa "<<nume<<" se afla printre trupele cu profit mic provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<std::endl;
}
