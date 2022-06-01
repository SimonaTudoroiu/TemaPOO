//
// Created by Simona on 5/31/2022.
//

#ifndef OOP_SORTARE_DISCURI_H
#define OOP_SORTARE_DISCURI_H

#include "strategy.h"

class sortare_discuri {
private:
    strategy *strategy_;
public:
    sortare_discuri(strategy *strategy = nullptr) : strategy_(strategy) {}
    ~sortare_discuri(){
        delete this->strategy_;
    }
    void set_strategy(strategy *strategy){
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    void do_sort() const {
        std::string rezultat = this->strategy_->sortarea();
        std::cout<<rezultat<<std::endl;
        std::cout<<"Discurile sunt sortate!"<<std::endl;

    }
};


#endif //OOP_SORTARE_DISCURI_H
