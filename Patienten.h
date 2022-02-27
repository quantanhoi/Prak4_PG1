#ifndef PATIENTEN_H
#define PATIENTEN_H
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
//#include<string.h>
/*#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>*/
#include"Krankenhaus.h"
#include"names.h"

using namespace std;


#define log(x) cout << x << endl;
enum geschlecht {
    mannlich, weiblich, divers
};
enum diagnose {
    simulant, infektion, fraktur, geheilt
};

//class Patienten;
//class Krankenhaus;
class Patienten {
private:
    geschlecht gender;
    string vorname;
    string nachname;
    string geburtsdatum;
    diagnose diag;
    int behandlungsdauer;
    int patientennummer;



public:
    static int listnummer;         //static listnummer
    geschlecht getGeschlecht();
    void printGeschlecht();
    string getVorname();
    string getNachname();
    string getVollname();
    string getGeburt();
    diagnose getDiag();
    void printDiag();
    int getBehandlungsdauer();
    void reduceDauer(int VergehenTag);
    void DiagzuGeheilt();
    void DiagZuDauer();
    void setGeburt();        //Input fuer Geburt
    void setName();             //Input fuer Nach- und Vorname
    void setDiag();         //Input fuer zufaellige Diagnose
    void DiagnoseAnpassung();
    void PrintAllInfo();    //Output fuer alle Infor
    void setPatientennummer();
    int getPatientennummer();


    Patienten() {         //default konstruktor
        diag = simulant;
        behandlungsdauer = 2;
    }
};
int Patienten::listnummer = 100000;     // funktioniert genau so wie ein globaler Variable, aber nur fuer Patienten

#endif // PATIENTEN_H
