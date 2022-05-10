//
// Created by Simona on 4/13/2022.
//

#include "abonament_standard.h"


abonament_standard::abonament_standard(int pret, int nrDiscuriPrimite, const disc &discStandard) : abonament(pret, nrDiscuriPrimite),
                                                                   disc_standard(discStandard) {}

abonament_standard::~abonament_standard() {

}

abonament_standard::abonament_standard(const abonament_standard &other) : abonament(other), disc_standard(other.disc_standard){}

abonament_standard& abonament_standard::operator=(const abonament_standard& other){
    abonament::operator=(other);
    disc_standard = other.disc_standard;
    return *this;
}


int abonament_standard::pret_abonament() {
    return getAbonament();
}

std::vector<std::string> abonament_standard::facilitati() {
    return {"primirea discului lunii la un pret redus","oprirea abonamentului oricand"};
}

int abonament_standard::getDiscuriPrimite() {
    return 1;
}





