//
// Created by Simona on 4/12/2022.
//

#ifndef OOP_CUMPARATOR_H
#define OOP_CUMPARATOR_H

#include <string>
#include <vector>
#include "disc.h"
#include "trupa.h"

class cumparator{
    int id_cumparator{1152};
    int buget{150};
    std::string nume;
    std::string prenume;
    std::string mail;
    disc d;
    trupa tr;
public:
    cumparator() = default;
    cumparator(int id_cumparator_, int buget_, const std::string& nume_, const std::string& prenume_, const std::string& mail_, const disc& d_, const trupa& tr_);

    friend std::ostream &operator<<(std::ostream &os, const cumparator &cumparator);
    void poate_cumpara();
    void exista_discul(std::vector <std::string> piese_preferate);
};



#endif //OOP_CUMPARATOR_H
