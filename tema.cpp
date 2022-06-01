#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "piesa.h"
#include "disc.h"
#include "trupa.h"
#include "cumparator.h"
#include "abonament.h"
#include "abonament_standard.h"
#include "abonament_premium.h"
#include "abonat.h"
#include "eroare_aplicatie.h"
#include "sortare_discuri.h"
#include "sortare_crescatoare.h"
#include "sortare_descrescatoare.h"

using namespace std;

int main()
{
    ifstream fin("date.txt");

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

    abonament_standard as(15,1,d1);
    abonament_premium ap(25,2,{d1,d2},10);

    bool meniu = true;

    while(meniu) {

        cout<<"Bine ati venit in lumea discografiei."<<endl;
        cout<<"Avem bagate in baza noastra de date o multitudine de discuri, trupe, si piese."<<endl;
        cout<<"Pentru a accesa un anumit serviciu, va rugam sa introduceti un numar de la 1 la 8, si sa apasati tasta enter."<<endl;
        cout<<"Optiunile sunt:"<<endl;
        cout<<"0 -> Iesiti din program."<<endl;
        cout<<"1 -> Detalii despre trupele bagate in baza noastra de date."<<endl;
        cout<<"2 -> Detalii despre discurile bagate in baza noastra de date."<<endl;
        cout<<"3 -> Detalii despre piesele bagate in baza noastra de date."<<endl;
        cout<<"4 -> Gestionare discuri dupa un anumit an."<<endl;
        cout<<"5 -> Gestionare piese dupa un an dat ce reprezinta anul aparitiei discului din care fac parte piesele."<<endl;
        cout<<"6 -> Clasamentul trupelor."<<endl;
        cout<<"7 -> Pot cumpara clientii introdusi in baza de date discul dorit?"<<endl;
        cout<<"8 -> Existenta unui disc cu anumite piese."<<endl;
        cout<<"9 -> Sortarea discurilor crescator dupa an."<<endl;
        cout<<"10 -> Sortarea discurilor descrescator dupa an."<<endl;
        cout<<"11 -> Vreti sa deveniti abonatul nostru? Sunteti pasionat de muzica si vreti sa primiti lunar unul sau mai multe discuri direct la voi acasa la un pret redus? Atunci aruncati o privire la facilitatile fiecarui abonament!"<<endl;
        cout<<"12 -> V-ati hotarat si vreti sa deveniti abonatul nostru? Atunci va rugam sa va introduceti datele cerute pentru a va putea inregistra. In cazul in care optati pentru un abonament premium, va rugam sa introduceti si discul ales pe care vreti sa il primiti."<<endl;
        cout<<"13 -> Sunteti elev, student sau pensionar? Avem abonamente la preturi speciale pentru dumneavoastra!"<<endl;
        int k;
        cout<<endl<<"Introduceti numarul dorit: ";
        cin>>k;
        unsigned long long i;

        switch (k) {
            case 0:{
                meniu = false;
                break;
            }
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
                cout << endl
                     << "Introduceti un an pentru a se afisa piesele ce apar in discurile lansate in anul introdus:";
                int nt;
                cin >> nt;
                for (i = 0; i < discuri_.size(); i++)
                    discuri_[i].gestionare_piese_dupa_anul_discului(nt);
                break;
            }
            case 6: {
                for (i = 0; i < trupa_.size(); i++)
                    trupa_[i].clasificare_trupa();
                break;
            }
            case 7: {
                cout << "Urmatoarea lista arata daca cumparatorii pot achizitiona discul dorit" << endl;
                for (i = 0; i < cumparatori.size(); i++) {
                    cumparatori[i].poate_cumpara();
                    cout << endl;
                }
                break;
            }
            case 8: {
                cout
                        << "Introduceti piesele voastre preferate si verificati daca exista un disc ce le include pe toate. La final, introduceti caracterul '#'.";
                vector<string> piese_preferate1;
                string p;
                cin >> p;
                while (p != "#") {
                    piese_preferate1.push_back(p);
                    cin >> p;
                }
                c1.exista_discul(piese_preferate1);
                break;
            }
            case 9:{
                sortare_discuri *sd = new sortare_discuri( new sortare_crescatoare(discuri_));
                cout<<"Discurile sortate crescator:"<<endl;
                sd->do_sort();
                cout<<endl;
                delete sd;
                break;
            }
            case 10 :{
                sortare_discuri *sd = new sortare_discuri( new sortare_descrescatoare(discuri_));
                cout<<"Discurile sortate descrescator:"<<endl;
                sd->do_sort();
                cout<<endl;
                delete sd;
                break;
            }
            case 11: {
                cout << "Facilitatile abonamentului standard:" << endl;
                vector<string> v = as.facilitati();
                for (i = 0; i < v.size(); i++)
                    cout << v[i] << endl;
                cout << endl << "Facilitatile abonamentului premium:" << endl;
                v = ap.facilitati();
                for (i = 0; i < v.size(); i++)
                    cout << v[i] << endl;
                break;
            }
            case 12: {
                try {
                    abonat ab;
                    cin >> ab;
                    if(ab.get_tip_abonament()=="Standard"){
                        abonament_standard as_(15, 1, d1);
                        abonamente_disponibile ad(as_);
                        cout<<"Pret pentru standard: "<<ad.pret_pe_luna<abonament_standard>(as_)<<endl;
                        ad.gestioneaza_abonamentele();
                        if(ad.nu_mai_exista() == true)
                            cout<<"Din fericire, mai exista abonamente standard!!"<<endl;
                        else if(ad.nu_mai_exista() == false)
                            break;
                    }
                    if(ab.get_tip_abonament()=="Premium"){
                        abonament_premium ap_(25, 2, {d1, d2}, 10);
                        abonamente_disponibile ad(ap_);
                        cout<<"Pret pentru premium: "<<ad.pret_pe_luna<abonament_premium>(ap_)<<endl;
                        ad.gestioneaza_abonamentele();
                        if(ad.nu_mai_exista() == true)
                            cout<<"Din fericire, mai exista abonamente premium!!"<<endl;
                        else if(ad.nu_mai_exista() == false)
                            break;
                    }
                    if (ab.poate_cumpara_abonamentul() == false) {
                        cout << endl;
                        break;
                    } else {
                        cout << endl;
                        cout << "Acum sunteti unul dintre abonatii nostrii." << endl;

                        bool st = true;
                        while (st) {
                            if (ab.get_tip_abonament() == "Standard") {

                                abonament_standard as1(15, 1, d1);
                                cout
                                        << "Acestea sunt facilitatile dumneavoastra pentru abonamentul standard care costa "
                                        << as1.pret_abonament() << " de lei, si unde veti primi "
                                        << "un disc." << endl;
                                bool meniu_standard = true;

                                while (meniu_standard) {
                                    cout << "Opiunile abonamentului standard:" << endl;
                                    cout << "0 -> Renuntare la abonament." << endl;
                                    cout << "1 -> Verificarea datelor dumneavoastra pe care noi le stocam." << endl;
                                    cout
                                            << "2 -> Verificarea facilitatilor abonamentului premium si standard, pentru comparatie, sau pentru un upgrade la abonamentul premium in cazul in care doriti acest lucru."
                                            << endl;

                                    int k1;
                                    cin >> k1;
                                    switch (k1) {
                                        case (0): {
                                            cout
                                                    << "Ne pare rau ca nu mai doriti sa fiti abonatul nostru. Chiar daca nu mai sunteti abonat, tot puteti naviga prin optiunile noastre principale."
                                                    << endl;
                                            meniu_standard = false;
                                            st = false;
                                            break;
                                        }
                                        case (1): {
                                            cout << ab << endl;
                                            break;
                                        }
                                        case (2): {
                                            ab.getTipAbonament()->beneficii_abonament();
                                            cout
                                                    << "Vreti sa faceti upgrade la abonament premium?(Introduceti Da sau Nu)"
                                                    << endl;
                                            string s;
                                            cin >> s;
                                            if (s == "Da") {
                                                ab.setTipAbonament("Premium");
                                                if (ab.poate_cumpara_abonamentul_2() == true) {
                                                    abonament *a = new abonament_premium(25, 2, {d1, d2}, 10);
                                                    abonament_premium *ap1 = dynamic_cast<abonament_premium *>(a);
                                                    ab.getTipAbonament()->upgrade_premium();
                                                    cout
                                                            << "Acestea sunt facilitatile dumneavoastra pentru abonamentul premium care costa "
                                                            << ap1->pret_abonament() << " de lei, si unde veti primi "
                                                            << a->getDiscuriPrimite() << " discuri." << endl;
                                                    vector<string> f1 = ap1->facilitati();
                                                    for (i = 0; i < f1.size(); i++)
                                                        cout << "-" << f1[i] << endl;
                                                    cout << endl;

                                                    bool submeniu_standard = true;
                                                    while (submeniu_standard) {
                                                        cout << "Opiunile abonamentului premium:" << endl;
                                                        cout << "0 -> Renuntare la card premium." << endl;
                                                        cout
                                                                << "1 -> Verificarea pretului fiecarul disc cu reducere aplicata."
                                                                << endl;
                                                        cout << "2 -> Gestionare discuri primite." << endl;

                                                        int t;
                                                        cin >> t;
                                                        switch (t) {
                                                            case (0): {
                                                                submeniu_standard = false;
                                                                break;
                                                            }
                                                            case (1): {
                                                                for (i = 0; i < discuri_.size(); i++) {
                                                                    cout << "Pentru " << discuri_[i].getNumeDisc()
                                                                         << ", pretul dupa reducere este: "
                                                                         << ap1->disc_cu_reducere(discuri_[i]) << "."
                                                                         << endl;
                                                                }
                                                                cout << endl;
                                                                break;
                                                            }
                                                            case (2): {
                                                                cout << "Discurile pe care le primiti luna asta sunt:"
                                                                     << endl;
                                                                ap1->interogare_discuri_primite();
                                                                break;
                                                            }

                                                        }
                                                    }
                                                } else {
                                                    ab.setTipAbonament("Standard");
                                                    cout << "Nu poti face upgrade la abonamentul Premium. Ne pare rau!"
                                                         << endl;
                                                    break;
                                                }
                                            }
                                            break;
                                        }

                                    }
                                }
                            } else if (ab.get_tip_abonament() == "Premium") {
                                abonament_premium apr(25, 2, {d1, d2}, 10);
                                cout
                                        << "Acestea sunt facilitatile dumneavoastra pentru abonamentul premium care costa "
                                        << apr.pret_abonament() << " de lei, si unde veti primi "
                                        << "doua discuri." << endl;

                                bool meniu_premium = true;
                                while (meniu_premium) {
                                    cout << "Opiunile abonamentului premium:" << endl;
                                    cout << "0 -> Renuntare la abonament." << endl;
                                    cout << "1 -> Verificarea datelor dumneavoastra pe care noi le stocam." << endl;
                                    cout
                                            << "2 -> Verificarea facilitatilor abonamentului premium si standard, pentru comparatie, sau pentru un downgrade la abonamentul standard in cazul in care doriti acest lucru."
                                            << endl;

                                    int k2;
                                    cin >> k2;
                                    switch (k2) {
                                        case (0): {
                                            cout
                                                    << "Ne pare rau ca nu mai doriti sa fiti abonatul nostru. Chiar daca nu mai sunteti abonat, tot puteti naviga prin optiunile noastre principale."
                                                    << endl;
                                            meniu_premium = false;
                                            st = false;
                                            break;
                                        }
                                        case (1): {
                                            cout << apr << endl;
                                            break;
                                        }
                                        case (2): {
                                            ab.getTipAbonament()->beneficii_abonament();
                                            cout
                                                    << "Vreti sa faceti downgrade la abonament standard?(Introduceti Da sau Nu)"
                                                    << endl;
                                            string s1;
                                            cin >> s1;
                                            if (s1 == "Da") {

                                                ab.setTipAbonament("Standard");
                                                meniu_premium = false;

                                            } else if (s1 == "Nu") {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
                catch (eroare_aplicatie& err){
                    cout<<err.what();
                }
            }
            case 13:{
                abonat a ;
                cin>>a;
                if(a.get_tip_abonament()=="Redus")
                {
                    a.reducerea_abonamentului();
                }
                else{
                    cout<<"Sunteti in ramura abonamentelor reduse!"<<endl;
                }
                break;
            }
        }
    }
    return 0;
}
