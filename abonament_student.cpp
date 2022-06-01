//
// Created by Simona on 6/1/2022.
//

#include "abonament_student.h"

abonament_student::abonament_student(int anIncepereStudii, int anTerminareStudii) : an_incepere_studii(
        anIncepereStudii), an_terminare_studii(anTerminareStudii){}

abonament_student::~abonament_student() {

}

int abonament_student::pret_abonament_redus() {
    return reducere_student;
}

void abonament_student::perioada_reducere() {
    if(an_incepere_studii <= 2022 && an_terminare_studii >= 2022)
        std::cout<< "Reducerea dumneavoastra se aplica pana in anul "<<an_terminare_studii<<", fiind nevoie de o verificare anuala a faptului ca ati ramas student."<<std::endl;
    else
        std::cout<<"Nu mai beneficiati de reducerea de student!"<<std::endl;
}


