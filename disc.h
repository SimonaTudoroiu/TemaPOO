//
// Created by Simona on 4/12/2022.
//

#ifndef OOP_DISC_H
#define OOP_DISC_H


#include <string>
#include "piesa.h"
#include <vector>
class disc {
    std::string nume_disc;
    int an_aparitie{2000};
    int nr_vanzari_lunar{100};
    int pret{50};
    std::vector<piesa> piese;
public:
    disc() =default;
    disc(const std::string& nume_disc_, int an_aparitie_, int nr_vanzari_lunar_, int pret_, const std::vector<piesa> &piese_);

    friend std::ostream& operator<<(std::ostream& os, const disc& d);

    const std::string& getNumeDisc();
    int getPret();
    bool piese_in_disc(std::vector<std::string> piesele);
    void afisare_discuri_aparute_in_anul_n (int an_);
    void gestionare_piese_dupa_anul_discului(int an_);
    int profit_lunar ();
};


#endif //OOP_DISC_H
