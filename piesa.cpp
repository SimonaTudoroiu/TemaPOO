//
// Created by Simona on 4/12/2022.
//

#include "piesa.h"
#include <iostream>
piesa::piesa(const std::string &nume_piesa_, const std::string &nume_trupa_) : nume_piesa{nume_piesa_}, nume_trupa{nume_trupa_}{}

std::ostream &operator<<(std::ostream &os, const piesa &p) {
    os<<"Numele piesei: "<<p.nume_piesa<<", numele trupei: "<<p.nume_trupa<<".";
    return os;
}

const std::string &piesa::getNumePiesa() {return nume_piesa;}
