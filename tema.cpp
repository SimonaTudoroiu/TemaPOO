#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("date.txt");
class trupa{
    string nume;
    string solist;
    int an_infiintare;
public:
    trupa() =default ;
    trupa(const string& nume_, const string& solist_, int an_infiintare_): nume{nume_}, solist{solist_}, an_infiintare{an_infiintare_}{}
    trupa(const trupa& other) : nume{other.nume}, solist{other.solist}, an_infiintare{other.an_infiintare}{}
    trupa& operator=(const trupa& other) {
        nume = other.nume;
        solist = other.solist;
        an_infiintare = other.an_infiintare;
        return *this;
    }
    ~trupa() {}
    friend ostream& operator<<(ostream& os, const trupa& tr) {
        os<<"Nume trupa: "<<tr.nume<<", an de infiintare al trupei: "<<tr.an_infiintare<<", solistul trupei: "<<tr.solist<<".";
        return os;
    }
    const string& getNumeTrupa() const { return nume;}
    int getAnInfiintare() const {return an_infiintare;}

};

class disc {
    string nume_disc;
    int an_aparitie;
    int nr_vanzari_lunar;
    int pret;
    trupa tr;
public:
    disc() =default;
    disc(const string& nume_disc_, int an_aparitie_, int nr_vanzari_lunar_, int pret_, const trupa& tr_): nume_disc{nume_disc_}, an_aparitie{an_aparitie_}, nr_vanzari_lunar{nr_vanzari_lunar_}, pret{pret_}, tr{tr_}{}
    friend ostream& operator<<(ostream& os, const disc& d) {
        os<<"Numele discului: "<<d.nume_disc<<", numele trupei: "<<d.tr.getNumeTrupa()<<", anul aparitiei: "<<d.an_aparitie<<", numarul de vanzari ale discului: "<<d.nr_vanzari_lunar<<", pretul discului: "<<d.pret;
        return os;
    }
    const string& getNumeDisc() const { return nume_disc;}
    void gestionare_discuri(const string& nume_){
        if (nume_==tr.getNumeTrupa())
            cout<<tr<<endl;
    }
    void afisare_discuri_aparute_in_anul_n (int an_){
        if (an_==an_aparitie)
            cout<<nume_disc<<" ";
    }
    bool poate_cumpara_discul (int n) {
        if (n>=pret)
            return true;
        else
            return false;
    }
    bool cumparare_dupa_an(int an_infiintare_, int bani ){
        if (an_infiintare_<=tr.getAnInfiintare())
            if(poate_cumpara_discul(bani))
                return true;
        return false;
    }
    int profit_lunar () {
        int profit;
        profit=nr_vanzari_lunar*pret;
        return profit;
    }
};

class piesa {
    string nume_piesa;
    string nume_trupa;
    disc d;
public:
    piesa() =default ;
    piesa(const string& nume_piesa_, const string& nume_trupa_, const disc& d_): nume_piesa{nume_piesa_}, nume_trupa{nume_trupa_}, d{d_} {}
    friend ostream& operator<<(ostream& os, const piesa& p) {
        os<<"Numele piesei: "<<p.nume_piesa<<", numele trupei: "<<p.nume_trupa<<", discul in care apare piesa: "<<p.d.getNumeDisc();
        return os;
    }
    void gestionare_piese(const string& nume_piesa_){
        if(nume_piesa_==nume_piesa)
            cout<<d<<endl;
    }
    void gestionare_discuri_dupa_piesa ( const string& nume_piesa_) {
        if (nume_piesa_ == nume_piesa) {
            cout << "Numele trupei ce canta piesa este: " << nume_trupa << ".";
            cout << " Numele discului in care apare piesa introdusa este:" << d.getNumeDisc() << ".";
            cout << "Profitul lunar pe care discul il face este de " << d.profit_lunar()
                 << " lei, iar implicit cel anual este de " << d.profit_lunar() * 12 << " lei.";
            if (d.profit_lunar() >= 1500)
                cout << "Discurile trupei se afla in topul celor mai vandute discuri.";
        }
    }
};
int main()
{
    vector <trupa> trupa_;
    trupa t1{"trupa1","solist1",1969}, t2{"trupa2","solist2",2000}, t3{"trupa3","solist3",1990}, t4{"trupa4","solist4",1996},t5{"trupa5","solist5",2001}, t6{"trupa6","solist6",1989}, t7{"trupa7","solist7",1995}, t8{"trupa8","solist8",2005}, t9{"trupa9","solist9",2000}, t10{"trupa10","solist10",2004};
    trupa_.push_back(t1);
    trupa_.push_back(t2);
    trupa_.push_back(t3);
    trupa_.push_back(t4);
    trupa_.push_back(t5);
    trupa_.push_back(t6);
    trupa_.push_back(t7);
    trupa_.push_back(t8);
    trupa_.push_back(t9);
    trupa_.push_back(t10);
    vector <disc> discuri_;
    disc d1{"disc1",1976,1000,50, t1}, d2{"disc2", 1986, 500, 35, t2}, d3{"disc3",2000, 30, 10,t3}, d4{"disc4",1999,68,22,t4}, d5{"disc5",2005, 47, 17,t5}, d6{"disc6",2001,80,68,t6}, d7{"disc7",1998,44,32,t7}, d8{"disc8",2015,33,16,t8}, d9{"disc9",2002,100,60,t9}, d10{"disc10",2010,250,100,t10};
    discuri_.push_back(d1);
    discuri_.push_back(d2);
    discuri_.push_back(d3);
    discuri_.push_back(d4);
    discuri_.push_back(d5);
    discuri_.push_back(d6);
    discuri_.push_back(d7);
    discuri_.push_back(d8);
    discuri_.push_back(d9);
    discuri_.push_back(d10);
    vector <piesa> piesa_;
    piesa p1{"piesa1","trupa1",d1}, p2{"piesa2","trupa2",d2}, p3{"piesa3","trupa3",d3}, p4{"piesa4","trupa4",d4}, p5{"piesa5","trupa5",d5}, p6{"piesa6","trupa6",d6}, p7{"piesa7","trupa7",d7}, p8{"piesa8","trupa8",d8}, p9{"piesa9","trupa9",d9}, p10{"piesa10","trupa10",d10};
    piesa_.push_back(p1);
    piesa_.push_back(p2);
    piesa_.push_back(p3);
    piesa_.push_back(p4);
    piesa_.push_back(p5);
    piesa_.push_back(p6);
    piesa_.push_back(p7);
    piesa_.push_back(p8);
    piesa_.push_back(p9);
    piesa_.push_back(p10);
    cout<<"Bine ati venit in lumea discografiei."<<endl;
    cout<<"Avem bagate in baza noastra de date o multitudine de discuri, trupe, si piese."<<endl;
    cout<<"Pentru a accesa un anumit serviciu, va rugam sa introduceti un numar de la 1 la 8, si sa apasati tasta enter."<<endl;
    cout<<"Optiunile sunt:"<<endl;
    cout<<"1 -> Detalii despre discurile bagate in baza noastra de date."<<endl;
    cout<<"2 -> Detalii despre trupele bagate in baza noastra de date."<<endl;
    cout<<"3 -> Detalii despre piesele bagate in baza noastra de date."<<endl;
    cout<<"4 -> Gestionare discuri dupa un anumit an."<<endl;
    cout<<"5 -> Gestionare discuri, in detaliu, dupa numele unei trupe."<<endl;
    cout<<"6 -> Gestionare discuri, in detaliu, dupa numele unei piese."<<endl;
    cout<<"7 -> Gestionare castiguri discuri dupa numele unei piese."<<endl;
    cout<<"8 -> Gestionare discuri dupa an si un buget dat."<<endl;
    int k;
    cout<<endl<<"Introduceti numarul dorit: ";
    fin>>k;
    unsigned long long i;
    switch (k) {
        case 1: {
            cout << "Detalii despre discurile bagate in baza noastra de date: " << endl;
            for (i = 0; i < discuri_.size(); i++)
                cout << discuri_[i] << endl;
            break;
        }
        case 2: {
            cout << "Detalii despre trupele bagate in baza noastra de date: " << endl;
            for (i = 0; i < trupa_.size(); i++)
                cout << trupa_[i] << endl;
            break;
        }
        case 3: {
            cout << "Detalii despre piesele bagate in baza noastra de date: " << endl;
            for (i = 0; i < piesa_.size(); i++)
                cout << piesa_[i] << endl;
            break;
        }
        case 4: {
            cout << "Alegeti un an pentru care ati vrea sa stiti ce discuri au aparut atunci:";
            int n;
            fin >> n;
            cout << endl << "Aceste discuri au aparut in anul selectat:" << endl;
            for (i = 0; i < discuri_.size(); i++)
                discuri_[i].afisare_discuri_aparute_in_anul_n(n);
            break;
        }
        case 5: {
            cout << endl << "Introduceti un nume de trupa pentru a se afisa detalii despre discurile lor:";
            string nt;
            fin >> nt;
            for (i = 0; i < trupa_.size(); i++)
                discuri_[i].gestionare_discuri(nt);
            break;
        }
        case 6: {
            cout << "Introduceti numele unei piese pentru a va afisa detalii despre discul in care aceasta apare:";
            string np;
            fin >> np;
            for (i = 0; i < piesa_.size(); i++)
                piesa_[i].gestionare_piese(np);
            break;
        }
        case 7: {
            cout<< "Introduceti numele unei piese pentru a va oferi informatii detaliate despre castigurile discului in care apare:";
            string np2;
            fin >> np2;
            for (i = 0; i < piesa_.size(); i++)
                piesa_[i].gestionare_discuri_dupa_piesa(np2);
            break;
        }
        case 8: {
            cout << endl<< "Introduceti un an si un buget pentru a verifica daca va puteti cumpara un disc aparut cel tarziu in acel an:";
            unsigned an1, buget1;
            fin >> an1 >> buget1;
            cout << "Poti cumpara discurile: ";
            for (i = 0; i < trupa_.size(); i++)
                if (discuri_[i].cumparare_dupa_an(an1, buget1))
                    cout << discuri_[i].getNumeDisc() << " ";
            break;
        }
    }
    return 0;
}