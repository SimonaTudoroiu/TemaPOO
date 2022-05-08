//
// Created by Simona on 4/13/2022.
//

#include "abonament.h"

abonament::abonament(int pret, int nrDiscuriPrimite) : pret(pret), nr_discuri_primite(nrDiscuriPrimite) {}

abonament::~abonament() {

}

abonament::abonament(const abonament &other) : aplicatie(other){
    pret = other.pret;
    nr_discuri_primite = other.nr_discuri_primite;
}

abonament& abonament::operator=(const abonament &other) {
    pret = other.pret;
    nr_discuri_primite = other.nr_discuri_primite;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const abonament &abonament) {
    os <<"Pretul abonamentului: " << abonament.pret << ", numarul de discuri pe care abonatul il va primi: " << abonament.nr_discuri_primite<<"."<<std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, abonament &abonament) {
    is>>abonament.pret>>abonament.nr_discuri_primite;
    return is;
}
int abonament::getAbonament() {
    return pret;
}

int abonament::getDiscuriPrimite() {
    return nr_discuri_primite;
}



int abonament::pret_abonament() {
    return pret;
}









