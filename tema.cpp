#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("date.txt");
class piesa {
    string nume_piesa;
    string nume_trupa;
public:
    piesa() =default;
    piesa(const string& nume_piesa_, const string& nume_trupa_): nume_piesa{nume_piesa_}, nume_trupa{nume_trupa_}{}
    friend ostream& operator<<(ostream& os, const piesa& p) {
        os<<"Numele piesei: "<<p.nume_piesa<<", numele trupei: "<<p.nume_trupa<<".";
        return os;
    }
    const string& getNumePiesa() {return nume_piesa;}
};

class disc {
    string nume_disc;
    int an_aparitie{2000};
    int nr_vanzari_lunar{100};
    int pret{50};
    vector<piesa> piese;
public:
    disc() =default;
    disc(const string& nume_disc_, int an_aparitie_, int nr_vanzari_lunar_, int pret_, const vector<piesa> &piese_): nume_disc{nume_disc_}, an_aparitie{an_aparitie_}, nr_vanzari_lunar{nr_vanzari_lunar_}, pret{pret_}, piese{piese_}{}

    friend ostream& operator<<(ostream& os, const disc& d) {
        os<<"Numele discului: "<<d.nume_disc<<", anul aparitiei: "<<d.an_aparitie<<", numarul de vanzari ale discului: "<<d.nr_vanzari_lunar<<", pretul discului: "<<d.pret<<"."<<endl;
        os<<"Piesele aparute pe discul "<<d.nume_disc<<" sunt:";
        for(unsigned long long i=0; i<d.piese.size();i++)
            os<<d.piese[i]<<" ";
        return os;
    }

    const string& getNumeDisc(){ return nume_disc;}
    int getPret(){ return pret;}
    bool piese_in_disc(vector<string> piesele){
        unsigned long long k=0;
        for(unsigned long long i=0;i<piesele.size();i++)
        {
            int ok=0;
            for(unsigned long long j=0;j<piese.size();j++)
                if(piesele[i]==piese[j].getNumePiesa())
                    ok=1;
            if(ok==1)
                k++;
        }
        if(k==piesele.size())
            return true;
        else
            return false;
    }
    void afisare_discuri_aparute_in_anul_n (int an_){
        if (an_==an_aparitie)
            cout<<nume_disc<<" ";
    }
    void gestionare_piese_dupa_anul_discului(int an_){
        if(an_==an_aparitie)
            for(unsigned long long i=0;i<piese.size();i++)
                cout<<piese[i]<<endl;
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
    int an_infiintare{1900};
    vector<disc> discuri;
public:
    trupa() =default ;
    trupa(const string& nume_, const string& solist_, int an_infiintare_, const vector<disc> &discuri_): nume{nume_}, solist{solist_}, an_infiintare{an_infiintare_}, discuri{discuri_}{}


    trupa(const trupa& other) : nume{other.nume}, solist{other.solist}, an_infiintare{other.an_infiintare}, discuri{other.discuri}{}
    trupa& operator=(const trupa& other) {
        nume = other.nume;
        solist = other.solist;
        an_infiintare = other.an_infiintare;
        discuri = other.discuri;
        return *this;
    }
    ~trupa() {}

    friend ostream& operator<<(ostream& os,  trupa& tr) {
        os<<"Nume trupa: "<<tr.nume<<", an de infiintare al trupei: "<<tr.an_infiintare<<", solistul trupei: "<<tr.solist<<".";
        for (unsigned long long i = 0;i<tr.discuri.size();i++)
            os<<tr.discuri[i]<<' ';
        return os;
    }

    bool verificare_disc(vector<string> piesele)
    {
        for(unsigned long long i=0;i<discuri.size();i++)
            if(discuri[i].piese_in_disc(piesele)==true)
                return true;
        return false;

    }
    void clasificare_trupa(){
        int k=0;
        for(unsigned long long i=0; i<discuri.size();i++)
            k = k + discuri[i].profit_lunar()*12;
        if(k > 10000)
            cout<<"Trupa "<<nume<<" se afla printre trupele cu profitul cel mai mare provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<endl;
        else if(k> 5000)
            cout<<"Trupa "<<nume<<" se afla printre trupele cu profit mediu provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<endl;
        else
            cout<<"Trupa "<<nume<<" se afla printre trupele cu profit mic provenit din vanzarea discurilor, acumuland "<<k<<" lei anual."<<endl;
    }
};
class cumparator{
    int id_cumparator{1152};
    int buget{150};
    string nume;
    string prenume;
    string mail;
    disc d;
    trupa tr;
public:
    cumparator() = default;
    cumparator(int id_cumparator_, int buget_, const string& nume_, const string& prenume_, const string& mail_, const disc& d_, const trupa& tr_): id_cumparator{id_cumparator_}, buget{buget_}, nume{nume_}, prenume{prenume_}, mail{mail_}, d{d_}, tr{tr_} {}

    friend ostream &operator<<(ostream &os, const cumparator &cumparator) {
        os << "Id-ul cumparatorului: " << cumparator.id_cumparator << ", buget: " << cumparator.buget << ", nume: "<< cumparator.nume << ", prenume: " << cumparator.prenume << ", mail: " << cumparator.mail<<".";
        return os;
    }
    void poate_cumpara(){
         if( d.getPret()<=buget)
             cout<<"Cumparatorul "<<nume<<" "<<prenume<<" poate cumpara discul "<<d.getNumeDisc()<<". Se va trimite un mail de confirmare a comenzii la adresa "<<mail<<".";
         else
             cout<<"Cumparatorul "<<nume<<" "<<prenume<<" nu poate cumpara discul "<<d.getNumeDisc()<<". Se va trimite un mail infirmare a comenzii la adresa "<<mail<<".";
    }
    void exista_discul(vector <string> piese_preferate){
        if(tr.verificare_disc(piese_preferate)==true)
            cout<<"Exista discul cu piesele enumerate.";
        else
            cout<<"Nu exista discul cu piesele enumerate.";
    }
};



int main()
{

    vector <piesa> piesa_;
    piesa p1("piesa1","trupa1");
    piesa p2("piesa2","trupa1");
    piesa p3("piesa3","trupa1");
    piesa p4("piesa4","trupa1");
    piesa p5("piesa5","trupa1");
    piesa p6("piesa6","trupa2");
    piesa p7("piesa7","trupa2");
    piesa p8("piesa8","trupa2");
    piesa p9("piesa9","trupa3");
    piesa p10("piesa10","trupa3");
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
    vector <disc> discuri_;

    disc d1("disc1",1976,1000,50,{p1,p2});
    disc d2("disc2", 1986, 500, 35,{p3, p4, p5});
    disc d3("disc3",2000, 30, 10,{p6, p7});
    disc d4("disc4",1999,68,22, {p8});
    disc d5("disc5",2005, 47, 17,{p9, p10});

    discuri_.push_back(d1);
    discuri_.push_back(d2);
    discuri_.push_back(d3);
    discuri_.push_back(d4);
    discuri_.push_back(d5);

    vector <trupa> trupa_;

    trupa t1("trupa1","solist1",1969,{d1, d2});
    trupa t2("trupa2","solist2",2000, {d3, d4});
    trupa t3("trupa3","solist3",1990,{d5});

    trupa_.push_back(t1);
    trupa_.push_back(t2);
    trupa_.push_back(t3);

    vector <cumparator> cumparatori;

    cumparator c1(1111,200,"nume1","prenume1","nume1.prenume1@yahoo.com",d1,t1);
    cumparator c2(2222, 400, "nume2", "prenume2","nume2.prenume2@yahoo.com", d2, t1);
    cumparator c3(3333, 50, "nume3", "prenume3","nume3.prenume3@yahoo.com", d3, t2);
    cumparator c4(4444, 10, "nume4", "prenume4","nume4.prenume4@yahoo.com", d4, t2);
    cumparator c5(5555, 5, "nume5", "prenume5","nume5.prenume5@yahoo.com", d5, t3);

    cumparatori.push_back(c1);
    cumparatori.push_back(c2);
    cumparatori.push_back(c3);
    cumparatori.push_back(c4);
    cumparatori.push_back(c5);

    cout<<"Bine ati venit in lumea discografiei."<<endl;
    cout<<"Avem bagate in baza noastra de date o multitudine de discuri, trupe, si piese."<<endl;
    cout<<"Pentru a accesa un anumit serviciu, va rugam sa introduceti un numar de la 1 la 8, si sa apasati tasta enter."<<endl;
    cout<<"Optiunile sunt:"<<endl;
    cout<<"1 -> Detalii despre trupele bagate in baza noastra de date."<<endl;
    cout<<"2 -> Detalii despre discurile bagate in baza noastra de date."<<endl;
    cout<<"3 -> Detalii despre piesele bagate in baza noastra de date."<<endl;
    cout<<"4 -> Gestionare discuri dupa un anumit an."<<endl;
    cout<<"5 -> Gestionare piese dupa un an dat ce reprezinta anul aparitiei discului din care fac parte piesele."<<endl;
    cout<<"6 -> Clasamentul trupelor."<<endl;
    cout<<"7 -> Pot cumpara clientii introdusi in baza de date discul dorit?"<<endl;
    cout<<"8 -> Existenta unui disc cu anumite piese."<<endl;
    int k;
    cout<<endl<<"Introduceti numarul dorit: ";
    cin>>k;
    unsigned long long i;
    switch (k) {
        case 1: {
            cout << "Detalii despre trupele bagate in baza noastra de date: " << endl;
            for (i = 0; i < trupa_.size(); i++)
                cout << trupa_[i] << endl;
            break;
        }
        case 2: {
            cout << "Detalii despre discurile bagate in baza noastra de date: " << endl;
            for (i = 0; i < discuri_.size(); i++)
                cout << discuri_[i] << endl;
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
            cin >> n;
            cout << endl << "Aceste discuri au aparut in anul selectat:" << endl;
            for (i = 0; i < discuri_.size(); i++)
                discuri_[i].afisare_discuri_aparute_in_anul_n(n);
            break;
        }
        case 5: {
            cout << endl << "Introduceti un an pentru a se afisa piesele ce apar in discurile lansate in anul introdus:";
            int nt;
            cin >> nt;
            for (i = 0; i < discuri_.size(); i++)
                discuri_[i].gestionare_piese_dupa_anul_discului(nt);
            break;
        }
        case 6: {
            for(i=0;i<trupa_.size();i++)
                trupa_[i].clasificare_trupa();
            break;
        }
        case 7: {
            cout<<"Urmatoarea lista arata daca cumparatorii pot achizitiona discul dorit"<<endl;
            for (i = 0; i < cumparatori.size(); i++) {
                cumparatori[i].poate_cumpara();
                cout<<endl;
            }
            break;
        }
        case 8: {
            cout <<"Introduceti piesele voastre preferate si verificati daca exista un disc ce le include pe toate. La final, introduceti caracterul '#'.";
            vector <string> piese_preferate1;
            string p;
            cin>>p;
            while(p!="#")
            {
                piese_preferate1.push_back(p);
                cin>>p;
            }
            c1.exista_discul(piese_preferate1);
            break;
        }
    }
    return 0;
}