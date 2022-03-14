
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
class discuri {
    string nume_disc;
    string nume_trupa;
    int an_aparitie;
    int nr_vanzari_lunar;
    int pret;
public:
    discuri() {nume_disc=""; nume_trupa=""; an_aparitie=0; nr_vanzari_lunar=0; pret=0;};
    discuri(const string& nume_disc_, const string& nume_trupa_, int an_aparitie_, int nr_vanzari_lunar_, int pret_): nume_disc{nume_disc_}, nume_trupa{nume_trupa_}, an_aparitie{an_aparitie_}, nr_vanzari_lunar{nr_vanzari_lunar_}, pret{pret_}{}
    friend ostream& operator<<(ostream& os, const discuri& d) {
        os<<"Numele discului: "<<d.nume_disc<<", numele trupei: "<<d.nume_trupa<<", anul aparitiei: "<<d.an_aparitie<<", numarul de vanzari ale discului: "<<d.nr_vanzari_lunar<<", pretul discului: "<<d.pret;
        return os;
    }
    const string& getNumeTrupa() const { return nume_trupa;}
    const string& getNumeDisc() const { return nume_disc;}
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
    int profit_lunar () {
        int profit;
        profit=nr_vanzari_lunar*pret;
        return profit;
    }
};
class trupa{
    string nume;
    string solist;
    int an_infiintare;
    int nr_albume;
    discuri disc;

public:
    trupa() { nume=""; solist=""; an_infiintare=0; nr_albume=0; discuri d1; disc=d1;};
    trupa(const string& nume_, const string& solist_, int an_infiintare_, int nr_albume_, const discuri& disc_): nume{nume_}, solist{solist_}, an_infiintare{an_infiintare_}, nr_albume{nr_albume_}, disc{disc_}{}
    trupa(const trupa& other) : nume{other.nume}, solist{other.solist}, an_infiintare{other.an_infiintare}, nr_albume{other.nr_albume}, disc{other.disc} {}
    trupa& operator=(const trupa& other) {
        nume = other.nume;
        solist = other.solist;
        an_infiintare = other.an_infiintare;
        nr_albume = other.nr_albume;
        disc=other.disc;
        return *this;
    }
    ~trupa() {}
    friend ostream& operator<<(ostream& os, const trupa& tr) {
        os<<"Nume trupa: "<<tr.nume<<", an de infiintare al trupei: "<<tr.an_infiintare<<", solistul trupei: "<<tr.solist<<", numar de albume concepute: "<<tr.nr_albume<<", nume disc: "<<tr.disc.getNumeDisc();
        return os;
    }
    void gestionare_discuri(const string& nume_){
        if (nume_==disc.getNumeTrupa())
            cout<<disc<<endl;
    }
    friend class discuri;
    bool cumparare_dupa_an(int an_infiintare_, int bani ){
        if (an_infiintare_<=an_infiintare)
            if(disc.poate_cumpara_discul(bani)==true)
                return true;
        return false;
    }
};

class piesa {
    string nume_piesa;
    string nume_trupa;
    discuri disc;
public:
    piesa() { nume_piesa=""; nume_trupa=""; discuri d1; disc=d1;};
    piesa(const string& nume_piesa_, const string& nume_trupa_, const discuri& disc_): nume_piesa{nume_piesa_}, nume_trupa{nume_trupa_}, disc{disc_} {}
    friend ostream& operator<<(ostream& os, const piesa& p) {
        os<<"Numele piesei: "<<p.nume_piesa<<", numele trupei: "<<p.nume_trupa<<", discul in care apare piesa: "<<p.disc.getNumeDisc();
        return os;
    }
    void gestionare_piese(const string& nume_piesa_){
        if(nume_piesa_==nume_piesa)
            cout<<disc<<endl;
    }
    void gestionare_discuri_dupa_piesa ( const string& nume_piesa_) {
        if (nume_piesa_ == nume_piesa) {
            cout << "Numele trupei ce canta piesa este: " << nume_trupa << ".";
            cout << " Numele discului in care apare piesa introdusa este:" << disc.getNumeDisc() << ".";
            cout << "Profitul lunar pe care discul il face este de " << disc.profit_lunar()
                 << " lei, iar implicit cel anual este de " << disc.profit_lunar() * 12 << " lei.";
            if (disc.profit_lunar() >= 1500)
                cout << "Discurile trupei se afla in topul celor mai vandute discuri.";
        }
    }
};
int main()
{
    vector <discuri> discuri_;
    discuri d1{"disc1","trupa1",1976,1000,50}, d2{"disc2","trupa2", 1986, 500, 35}, d3{"disc3","trupa3",2000, 30, 10}, d4{"disc4","trupa4",1999,68,22}, d5{"disc5","trupa5",2005, 47, 17}, d6{"disc6","trupa6",2001,80,68}, d7{"disc7","turpa7",1998,44,32}, d8{"disc8","trupa8",2015,33,16}, d9{"disc9","trupa9",2002,100,60}, d10{"disc10","trupa10",2010,250,100};
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
    vector <trupa> trupa_;
    trupa t1{"trupa1","solist1",1969,3,d1}, t2{"trupa2","solist2",2000,8,d2}, t3{"trupa3","solist3",1990, 5, d3}, t4{"trupa4","solist4",1996,3,d4},t5{"trupa5","solist5",2001,10,d5}, t6{"trupa6","solist6",1989,4,d6}, t7{"trupa7","solist7",1995,8,d7}, t8{"trupa8","solist8",2005,7,d8}, t9{"trupa9","solist9",2000,3,d9}, t10{"trupa10","solist10",2004,2,d10};
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
    cin>>k;
    system("cls");
    unsigned long long n,i;
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
            cin >> n;
            cout << endl << "Aceste discuri au aparut in anul selectat:" << endl;
            for (i = 0; i < discuri_.size(); i++)
                discuri_[i].afisare_discuri_aparute_in_anul_n(n);
            break;
        }
        case 5: {
            cout << endl << "Introduceti un nume de trupa pentru a se afisa detalii despre discurile lor:";
            string nt;
            cin >> nt;
            for (i = 0; i < trupa_.size(); i++)
                trupa_[i].gestionare_discuri(nt);
            break;
        }
        case 6: {
            cout << "Introduceti numele unei piese pentru a va afisa detalii despre discul in care aceasta apare:";
            string np;
            cin >> np;
            for (i = 0; i < piesa_.size(); i++)
                piesa_[i].gestionare_piese(np);
            break;
        }
        case 7: {
            cout<< "Introduceti numele unei piese pentru a va oferi informatii detaliate despre castigurile discului in care apare:";
            string np2;
            cin >> np2;
            for (i = 0; i < piesa_.size(); i++)
                piesa_[i].gestionare_discuri_dupa_piesa(np2);
            break;
        }
        case 8: {
            cout << endl<< "Introduceti un an si un buget pentru a verifica daca va puteti cumpara un disc aparut cel tarziu in acel an:";
            int an1, buget1;
            cin >> an1 >> buget1;
            cout << "Poti cumpara discurile: ";
            for (i = 0; i < trupa_.size(); i++)
                if (trupa_[i].cumparare_dupa_an(an1, buget1) == true)
                    cout << discuri_[i].getNumeDisc() << " ";
            break;
        }
    }
    return 0;
}