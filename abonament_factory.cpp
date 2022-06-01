//
// Created by Simona on 6/1/2022.
//

#include "abonament_factory.h"
#include "abonament_student.h"
#include "abonament_elev.h"
#include "abonament_pensionar.h"

abonamente_reduse* abonament_factory::newAbon(const std::string &alegere) {
    if(alegere == "student") {
        int i,s;
        std::cout<<"Anul de inceput al studiilor:"<<std::endl;
        std::cin>>i;
        std::cout<<"Anul de terminare al studiilor:"<<std::endl;
        std::cin>>s;
        return new abonament_student(i,s);
    }    else if (alegere == "elev") {
        int i,s;
        std::cout<<"Anul de inceput al scolii generale:"<<std::endl;
        std::cin>>i;
        std::cout<<"Anul de terminare al scolii generale:"<<std::endl;
        std::cin>>s;
        return new abonament_elev(i,s);
    }    else if (alegere == "pensionar") {
        int i;
        std::cout<<"Anul pensionarii:"<<std::endl;
        std::cin>>i;
        return new abonament_pensionar(i);
    }    else
        return nullptr;
}
