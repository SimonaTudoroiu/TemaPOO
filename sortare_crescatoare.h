//
// Created by Simona on 5/31/2022.
//

#ifndef OOP_SORTARE_CRESCATOARE_H
#define OOP_SORTARE_CRESCATOARE_H


#include "strategy.h"
#include <algorithm>

class sortare_crescatoare : public strategy {
    std::vector<disc> d;
public:
    explicit sortare_crescatoare(const std::vector<disc> &d) : d(d) {}

    std::string sortarea() override  {
        std::string rezultat;

        for(unsigned long long i = 0;i<d.size();i++)
            for(unsigned long long j=i+1;j<d.size();j++)
            {
                if(d[i].getPret()>d[j].getPret())
                {
                    std::swap(d[i], d[j]);
                }
            }
        for(unsigned long long i=0;i<d.size();i++)
        {
            rezultat += d[i].getNumeDisc();
            rezultat += " ";
        }
        return rezultat;
    }
};


#endif //OOP_SORTARE_CRESCATOARE_H
