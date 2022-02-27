#ifndef KRANKENHAUS_H
#define KRANKENHAUS_H
//#include"names.h"
#include"Patienten.h"


using namespace std;
#define log(x) cout << x << endl;

class Patienten;
class Krankenhaus{
private:
    vector<Patienten> PatList;
    const int BettAnzahl = 60;
    int aktuellBett;      //remaining Bed
public:
    Krankenhaus() {
        aktuellBett = BettAnzahl;    //default konstruktor
    }
    void addPatienten(Patienten& pa1);
    int checkPatList();
    int getAktuellBett();
    int ZeitSimulieren(int Vergehentag);
    bool checkRemainBett();
    int AddPatient(Patienten& p, int number);

};
int AddPatient(Patienten& pat1, Krankenhaus& kh1, int number);
#endif // KRANKENHAUS_H
