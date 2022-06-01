//
// Created by Simona on 6/1/2022.
//

#ifndef OOP_ABONAMENT_STUDENT_H
#define OOP_ABONAMENT_STUDENT_H


#include "abonamente_reduse.h"

class abonament_student : public abonamente_reduse{
    int an_incepere_studii;
    int an_terminare_studii;
    int reducere_student{0};
public:
    abonament_student() =default;

    abonament_student(int anIncepereStudii, int anTerminareStudii);

    virtual ~abonament_student();

    int pret_abonament_redus() override;

    void perioada_reducere() override;
};


#endif //OOP_ABONAMENT_STUDENT_H
