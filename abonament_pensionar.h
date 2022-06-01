//
// Created by Simona on 6/1/2022.
//

#ifndef OOP_ABONAMENT_PENSIONAR_H
#define OOP_ABONAMENT_PENSIONAR_H


#include "abonament.h"
#include "abonamente_reduse.h"

class abonament_pensionar : public abonamente_reduse{
    int an_pensionare;
    int reducere_pensionar{5};
public:
    abonament_pensionar() = default;

    virtual ~abonament_pensionar();

    abonament_pensionar(int anPensionare);

    int pret_abonament_redus() override;

    void perioada_reducere() override;
};


#endif //OOP_ABONAMENT_PENSIONAR_H
