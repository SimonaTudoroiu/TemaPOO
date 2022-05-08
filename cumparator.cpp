//
// Created by Simona on 4/12/2022.
//

#include "cumparator.h"
#include <string>
#include <iostream>
#include <vector>

cumparator::cumparator(int id_cumparator_, int buget_, const std::string &nume_, const std::string &prenume_, const std::string &mail_,
                       const disc &d_, const trupa &tr_) : id_cumparator{id_cumparator_}, buget{buget_}, nume{nume_}, prenume{prenume_}, mail{mail_}, d{d_}, tr{tr_} {}

std::ostream &operator<<(std::ostream &os, const cumparator &cumparator) {
    os << "Id-ul cumparatorului: " << cumparator.id_cumparator << ", buget: " << cumparator.buget << ", nume: "<< cumparator.nume << ", prenume: " << cumparator.prenume << ", mail: " << cumparator.mail<<".";
    return os;
}

void cumparator::poate_cumpara() {
    if( d.getPret()<=buget)
        std::cout<<"Cumparatorul "<<nume<<" "<<prenume<<" poate cumpara discul "<<d.getNumeDisc()<<". Se va trimite un mail de confirmare a comenzii la adresa "<<mail<<".";
    else
        std::cout<<"Cumparatorul "<<nume<<" "<<prenume<<" nu poate cumpara discul "<<d.getNumeDisc()<<". Se va trimite un mail infirmare a comenzii la adresa "<<mail<<".";
}

void cumparator::exista_discul(std::vector <std::string> piese_preferate) {
    if(tr.verificare_disc(piese_preferate)==true)
        std::cout<<"Exista discul cu piesele enumerate.";
    else
        std::cout<<"Nu exista discul cu piesele enumerate.";
}
