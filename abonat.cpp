//
// Created by Simona on 4/19/2022.
//

#include "abonat.h"
#include "nu_exista_abonament.h"

abonat::abonat(int bugetLunar, const std::string &tipAbonament, const std::string &discDorit) : buget_lunar(bugetLunar), tip_abonament(tipAbonament), disc_dorit(discDorit) {
    if(tipAbonament != "Standard" && tipAbonament != "Premium")
    {
        throw nu_exista_abonament("");
    }
    abonat::incrementeaza_id_abonat();
    id = id_abonat;
    abonament_factory a;
    af = a;

}


abonat::abonat(int bugetLunar, const std::string &tipAbonament) : buget_lunar(bugetLunar), tip_abonament(tipAbonament) {
    if(tipAbonament != "Standard" && tipAbonament != "Premium")
    {
        throw nu_exista_abonament("");
    }
    abonat::incrementeaza_id_abonat();
    id = id_abonat;
    abonament_factory a;
    af = a;
}


abonat::~abonat() {

}

std::ostream &operator<<(std::ostream &os, const abonat &abonat) {
    os <<"Detaliile retinute de noi despre dumneavoastra: "<<std::endl<<"Id: "<<abonat.id<<std::endl<<" Buget_lunar: " << abonat.buget_lunar << " ,tip_abonament: "
       << abonat.tip_abonament;
    if(abonat.tip_abonament == "Premium")
        os<<" ,disc_dorit: " << abonat.disc_dorit<<"."<<std::endl;
    else
        os<<"."<<std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, abonat &abonat) {
    abonat.incrementeaza_id_abonat();
    abonat.id = abonat.id_abonat;
    std::cout<<"Sunteti abonatul cu id_ul: "<<abonat.id<<std::endl;
    std::cout<<"Introduceti bugetul lunar pe care il aveti la dispozitie pentru acest abonament, si abonamentul dorit."<<std::endl;
    std::cout<<"Bugetul: ";
    is>>abonat.buget_lunar;
    std::cout<<std::endl;
    std::cout<<"Abonamentul dorit(Standard, Premium sau Redus): ";
    is>>abonat.tip_abonament;
    std::cout<<std::endl;
    if(abonat.tip_abonament == "Premium")
    {
        std::cout<<"Discul dorit:"<<std::endl;
        is>>abonat.disc_dorit;
    }
    return is;
}
std::shared_ptr<subscriptie> abonat::getTipAbonament() {
    return abon;
}

bool abonat::poate_cumpara_abonamentul() {
    if(tip_abonament=="Standard")
    {
        if(buget_lunar >= 15)
        {
            std::cout<<"Poti cumpara abonamentul standard.";
            return true;
        }
        else {
            std::cout<<"Nu poti cumpara abonamentul standard cu bugetul pe care il detineti. Ne pare rau!";
            return false;
        }
    }
    else if(tip_abonament=="Premium"){
        if(buget_lunar >= 25){
            std::cout<<"Poti cumpara abonamentul premium.";
            return true;
        }
        else
        {
            std::cout<<"Nu poti cumpara abonamentul standard cu bugetul pe care il detineti. Ne pare rau! Vreti sa incercati abonamentul standard?(Introduceti Da sau Nu)";
            std::string alegere;
            std::cin>>alegere;
            if(alegere=="Da")
            {
                if(buget_lunar >= 15)
                {
                    std::cout<<"Poti cumpara abonamentul standard.";
                    tip_abonament = "Standard";
                    return true;
                }
                else {
                    std::cout<<"Nu poti cumpara abonamentul standard cu bugetul pe care il detineti. Ne pare rau!";
                    return false;
                }
            }
            else if(alegere=="Nu")
            {
                std::cout<<"Ne pare rau ca nu va putem oferi serviciile noasre!";
                return false;
            }
            return false;
        }
    }
    return false;
}





std::string abonat::get_tip_abonament() {
    return tip_abonament;
}

void abonat::setTipAbonament( const std::string& tip_abonament_) {
    tip_abonament = tip_abonament_;
}

bool abonat::poate_cumpara_abonamentul_2() {
    if(tip_abonament == "Standard" && buget_lunar >= 15)
        return true;
    else if(tip_abonament == "Premium" && buget_lunar >= 25)
        return true;
    else
        return false;
}

int abonat::id_abonat = 0;

void abonat::incrementeaza_id_abonat() {
    id_abonat += 1;
}

void abonat::reducerea_abonamentului() {
    std::cout<<"Alegeti ce tip de reducere vi se potriveste (elev, student, pensionar):"<<std::endl;
    std::string alegere;
    std::cin>>alegere;
    if(alegere!="elev" && alegere!="student" && alegere!="pensionar")
    {
        std::cout<<"Nu ati ales o varianta valida!"<<std::endl;
        return;
    }
    else{
        abonamente_reduse *a = af.newAbon(alegere);
        int c=a->pret_abonament_redus();
        std::cout<<"Pretul abonamentului de "<<alegere<<" este de "<<c<<" lei."<<std::endl;
        std::cout<<"Mai jos puteti observa daca sunteti eligibil pentru abonamentul dorit, iar in caz afirmativ se va afisa perioada de reducere."<<std::endl;
        a->perioada_reducere();
    }
}




