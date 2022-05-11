//
// Created by Simona on 5/8/2022.
//

#ifndef OOP_SUBSCRIPTIE_H
#define OOP_SUBSCRIPTIE_H
#include <iostream>
#include <vector>

class subscriptie {
public:

    virtual int pret_abonament()=0;

    virtual std::vector<std::string> facilitati()=0;

    void beneficii_abonament();

    void upgrade_premium();
};


#endif //OOP_SUBSCRIPTIE_H
