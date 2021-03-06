#include"Patienten.h"
#include<iostream>
void Patienten::setPatientenNummer() {
    patientennummer = InitialListNummer;
    InitialListNummer++;
}
int Patienten::getPatientenummer() {
    return patientennummer;
}

void Patienten::PrintAllInfo() {
    log(getVollname());
    log("Geburtsdatum: "<< getGeburt());
    cout << "Geschlecht: ";
    printGeschlecht();
    printPatientenDiagnose();
    log("Behandlungsdauer(Tag): " << getBehandlungsdauer());
}

geschlecht Patienten::getGeschlecht() {
    return gender;
}
void Patienten::printGeschlecht() {
    if(getGeschlecht() == mannlich) log("mannlich");
    if(getGeschlecht() == weiblich) log("weiblich");
    if(getGeschlecht()==divers) log("divers");
}
string Patienten::getVorname() {
    return vorname;
}
string Patienten::getNachname() {
    return nachname;
}
string Patienten::getVollname() {
    string vollname = nachname + " " + vorname;
    return vollname;
}
string Patienten::getGeburt() {
    return geburtsdatum;
}
diagnose Patienten::getPatientenDiagnose() {
    return PatientenDiagnose;
}
int Patienten::getBehandlungsdauer() {
    return behandlungsdauer;
}
void Patienten::DiagZuDauer() {
    switch (PatientenDiagnose) {
        case simulant:
            behandlungsdauer = 2;
        break;
        case infektion:
            behandlungsdauer = 14;
        break;
        case fraktur:
            behandlungsdauer = 6*7;
        break;
        case geheilt:
            behandlungsdauer = 0;
        break;
    }
}
void Patienten::printPatientenDiagnose() {
    switch (PatientenDiagnose) {
        case simulant:
           log("Diagnose: Simulant");
        break;
        case infektion:
            log("Diagnose: Infektion");
        break;
        case fraktur:
            log("Diagnose: Fraktur");
        break;
        case geheilt:
            log("Diagnose: Geheilt");
        break;
    }
}

void Patienten::reduceDauer(int VergehenTag) {
    behandlungsdauer -= VergehenTag;      //Behandlungsdauer um n Tag reduzieren
}
void Patienten::DiagzuGeheilt() {
    if(getBehandlungsdauer() <= 0) {
        PatientenDiagnose = geheilt;
        log("Der Patient " << patientennummer << " wird geheilt.");
    }
}
void Patienten::setPatientenGeburtsdatum() {
    int randomday{};
    int randommonth{};
    int randomyear{};
    bool leapyear{};
    randomyear = rand()%101 + 1920;  //random year, try to make a bit sense
    if (randomyear % 4 == 0) {        //check if that year if a leap year
            if (randomyear % 100 == 0) {
                if (randomyear % 400 == 0)
                    leapyear = true;

                else
                        leapyear = false;
                }
            else
                leapyear = true;
            }
    else
        leapyear = false;
    randommonth = (rand()%12 + 1);           //Zufaelliger Monat
    switch(randommonth) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:    //Monate mit 31 Tage
            randomday = rand()%31 +1;
        break;
        case 2:
            if(leapyear == true) {               //Feb, leapyear oder nicht
                randomday = rand()%29 +1;
            }
            else
                randomday = rand()%28 +1;
        break;
        case 4: case 6: case 9: case 11:         //Monate mit 30 Tage
            randomday = rand()%30 +1;
        break;
        }
    //cout << randomday << "." << randommonth << "." << randomyear << endl;
    geburtsdatum = std::to_string(randomday) + "." + std::to_string(randommonth) + "."+ std::to_string(randomyear);
}
string getMaleName() {
    return firstNames_male[rand()%50];
}
string getLastnames() {
    return lastNames[rand()%50];
}
string getFemalename() {
    return firstNames_female[rand()%50];
}
void Patienten::setName(){
    int random;
    random = rand()%3;             //zufaellige Geschlecht
    gender = (geschlecht)random;
    if(gender == mannlich) {    //male patienten
        vorname = getMaleName();
        nachname = getLastnames();
    }
    if(gender == weiblich) {    // female patienten
        vorname = getFemalename();
        nachname = getLastnames();
    }
    if(gender == divers) {
        random = rand()%2;
        if(random == 0) {    //m??nnlicher Name
            vorname = getMaleName();
        }
        if(random == 1) {
            vorname = getFemalename();
        }
        nachname = getLastnames();
    }
}
void Patienten::setDiag() {       //Input for random diagnose
    int random = rand()%3+0;
    switch(random) {
    case 0:
        PatientenDiagnose = simulant;
        break;
    case 1:
        PatientenDiagnose = infektion;
        break;
    case 2:
        PatientenDiagnose = fraktur;
        break;
    }
    DiagZuDauer();
}
void Patienten::DiagnoseAnpassung() {      //Diagnose Anpassung, aber wofuer brauche ich diese?
    char choice;
    log("Which Diagnose do you want to change? \n1. Simulant\n2. Infektion\n 3. Fraktur\n4. Geheilt\n Your choice: ");
    cin >> choice;
    switch (choice) {
        case '1':
            PatientenDiagnose = simulant;
        break;
    case '2':
        PatientenDiagnose = infektion;
        break;
    case '3':
        PatientenDiagnose = fraktur;
        break;
    case 4:
        PatientenDiagnose = geheilt;
        break;
    default:
        break;
    }
    DiagZuDauer();
}
