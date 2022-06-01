//
// Created by Simona on 5/22/2022.
//

#ifndef OOP_ABONAMENTE_DISPONIBILE_H
#define OOP_ABONAMENTE_DISPONIBILE_H
#include <iostream>
#include "abonament_premium.h"
#include "abonament_standard.h"

template<class T>
class abonamente_disponibile {
    T a;
    static int a_p;
    static int a_s;
public:
    explicit abonamente_disponibile(T a_) : a(a_) {}

    static void decrementeaza_a_p(){
        a_p -=1;
    }
    static void decrementeaza_a_s(){
        a_s -=1;
    }
    void gestioneaza_abonamentele(){
        abonament_premium ap;
        abonament_standard as;
        if(typeid(a) == typeid(ap))
            abonamente_disponibile::decrementeaza_a_p();
        else if(typeid(a) == typeid(as))
            abonamente_disponibile::decrementeaza_a_s();

    }
    bool nu_mai_exista(){
        abonament_standard as;
        abonament_premium ap;
        if(typeid(a) == typeid(as))
            if(abonamente_disponibile::a_s < 0)
            {
                std::cout<<abonamente_disponibile::a_s<<std::endl;
                std::cout<<"Nu mai sunt abonamente standard!"<<std::endl;
                return false;
            }
            else{
                std::cout<<"Abonamente standard ramase: ";
                std::cout<<abonamente_disponibile::a_s<<std::endl;
                return true;
            }
        else
        if(typeid(a) == typeid(ap)) {
            if (abonamente_disponibile::a_p < 0) {
                std::cout<<abonamente_disponibile::a_p<<std::endl;
                std::cout << "Nu mai sunt abonamente premium!" << std::endl;
                return false;
            } else {
                std::cout<<"Abonamente premium ramase: ";
                std::cout<<abonamente_disponibile::a_p<<std::endl;
                return true;
            }
        }
        return false;
    }
    template <class T1>
    int pret_pe_luna(T1 ab)
    {
        return ab.pret_abonament();
    }
};

template<class T>
int abonamente_disponibile<T>::a_p = 100;

template<class T>
int abonamente_disponibile<T>::a_s = 100;


#include "abonamente_disponibile.cpp"
#endif //OOP_ABONAMENTE_DISPONIBILE_H
