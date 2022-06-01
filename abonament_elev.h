//
// Created by Simona on 6/1/2022.
//

#ifndef OOP_ABONAMENT_ELEV_H
#define OOP_ABONAMENT_ELEV_H

#include <iostream>
#include "abonament.h"
#include "abonamente_reduse.h"

class abonament_elev : public abonamente_reduse{
    int an_incepere_scoala;
    int an_terminare_scoala;
    int reducere_elev{12};
public:
    abonament_elev() =default;

    abonament_elev(int anIncepereScoala, int anTerminareScoala);

    virtual ~abonament_elev();

    int pret_abonament_redus() override;

    void perioada_reducere() override;
};


#endif //OOP_ABONAMENT_ELEV_H
