//
// Created by Simona on 4/12/2022.
//

#ifndef OOP_TRUPA_H
#define OOP_TRUPA_H

#include <string>
#include <vector>
#include "disc.h"

class trupa{
    std::string nume;
    std::string solist;
    int an_infiintare{1900};
    std::vector<disc> discuri;
public:
    trupa() =default ;
    trupa(const std::string& nume_, const std::string& solist_, int an_infiintare_, const std::vector<disc> &discuri_);


    trupa(const trupa& other);
    trupa& operator=(const trupa& other);
    ~trupa();

    friend std::ostream& operator<<(std::ostream& os,  trupa& tr);

    bool verificare_disc(std::vector<std::string> piesele);
    void clasificare_trupa();
};


#endif //OOP_TRUPA_H
