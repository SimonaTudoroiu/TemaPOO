//
// Created by Simona on 6/1/2022.
//

#include "abonament_pensionar.h"

abonament_pensionar::abonament_pensionar(int anPensionare) : an_pensionare(anPensionare) {}


abonament_pensionar::~abonament_pensionar() {

}

int abonament_pensionar::pret_abonament_redus() {
    return reducere_pensionar;
}

void abonament_pensionar::perioada_reducere() {
    if(an_pensionare <= 2022 )
        std::cout<< "Reducerea dumneavoastra este valabila non-stop!"<<std::endl;
    else
        std::cout<<"Nu beneficiati de reducerea de pensionar!"<<std::endl;
}

