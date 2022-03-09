#include <iostream>
#include <string>
using namespace std;
class trupa{
    string nume;
    string solist;
    int an_infiintare;
    int nr_albume;

public:
    trupa();
    trupa(string nn, int an, string s, int nr);
    ~trupa();
    trupa( const trupa& );
    trupa& operator=(const trupa&);
    friend ostream& operator<<(ostream& os, const trupa& t);
    friend istream& operator>>(istream& is, const trupa& t);
};
class discuri {
    string nume_disc;
    string trupa;
    int an_aparitie;
    int nr_vanzari;
public:
    discuri();
    discuri(string n, string tr, int a, int nrv);
    ~discuri();
    discuri(const discuri&);
    discuri& operator=(const discuri&);
    friend ostream& operator<<(ostream& os, const discuri& d);
    friend istream& operator>>(istream& is, const discuri& d);
};
class piesa {
    string trupa;
    string disc_aparitie;
public:
    piesa();
    piesa(string trp, string aparitie);
    ~piesa();
    piesa(const piesa&);
    piesa& operator=(const piesa&);
    friend ostream& operator<<(ostream& os, const piesa& p);
    friend istream& operator>>(istream& is, const piesa& p);
};

int main()
{
}
