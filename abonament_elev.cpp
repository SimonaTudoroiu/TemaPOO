//
// Created by Simona on 6/1/2022.
//

#include "abonament_elev.h"

abonament_elev::abonament_elev(int anIncepereScoala, int anTerminareScoala) : an_incepere_scoala(anIncepereScoala),
                                                                                             an_terminare_scoala(anTerminareScoala) {}
abonament_elev::~abonament_elev() {

}

int abonament_elev::pret_abonament_redus() {
    return reducere_elev;
}

void abonament_elev::perioada_reducere() {
    if(an_incepere_scoala <= 2022 && an_terminare_scoala >= 2022)
        std::cout<< "Reducerea dumneavoastra se aplica pana in anul "<<an_terminare_scoala<<", fiind nevoie de o verificare anuala a faptului ca ati ramas elev."<<std::endl;
    else
        std::cout<<"Nu mai beneficiati de reducerea de elev!"<<std::endl;
}


