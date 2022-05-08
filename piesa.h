//
// Created by Simona on 4/12/2022.
//

#ifndef OOP_PIESA_H
#define OOP_PIESA_H
#include <string>

class piesa {
    std::string nume_piesa;
    std::string nume_trupa;
public:
    piesa() =default;
    piesa(const std::string& nume_piesa_, const std::string& nume_trupa_);
    friend std::ostream& operator<<(std::ostream& os, const piesa& p);
    const std::string& getNumePiesa();
};


#endif //OOP_PIESA_H
