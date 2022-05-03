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

#define DEFAULT_BEHANDLUNGSDAUER 2
#define INITIAL_LISTNUMMER 100000
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
    diagnose PatientenDiagnose;
    int behandlungsdauer;
    int patientennummer;

//set, read, update, delete

public:
    static int InitialListNummer;         //static listnummer
    geschlecht getGeschlecht();
    void printGeschlecht();
    string getVorname();
    string getNachname();
    string getVollname();
    string getGeburt();
    diagnose getPatientenDiagnose();
    void printPatientenDiagnose();
    int getBehandlungsdauer();
    void reduceDauer(int VergehenTag);
    void DiagzuGeheilt();
    void DiagZuDauer();
    void setPatientenGeburtsdatum();        //Input fuer Geburt
    void setName();             //Input fuer Nach- und Vorname
    void setDiag();         //Input fuer zufaellige Diagnose
    void DiagnoseAnpassung();
    void PrintAllInfo();    //Output fuer alle Infor
    void setPatientenNummer();
    int getPatientenummer();
    void setGender();


    Patienten() {         //default konstruktor
        PatientenDiagnose = simulant;
        behandlungsdauer = DEFAULT_BEHANDLUNGSDAUER;
    }
};
int Patienten::InitialListNummer = INITIAL_LISTNUMMER;     // funktioniert genau so wie ein globaler Variable, aber nur fuer Patienten

#endif // PATIENTEN_H
