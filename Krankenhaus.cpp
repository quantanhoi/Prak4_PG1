#include"Krankenhaus.h"
#include<iostream>

int Krankenhaus::getAktuellBett() {
    return aktuellBett;
}

void Krankenhaus::addPatienten(Patienten& pa1) {  //adding patient to the list
    PatList.push_back(pa1);
    aktuellBett--;
}
int Krankenhaus::checkPatList(){

    cout << "\n\n Checking Patient List... \n\n";
    if(PatList.size() == 0) {
        log("Alle Patienten wurden geheilt!");
        return 0;
    }
    for
(unsigned int i = 0; i < PatList.size(); i++) {
       PatList.at(i).PrintAllInfo();
       log("Patientennummer " << PatList.at(i).getPatientenummer());
       cout << "\n";
    }
    return 0;
}
bool Krankenhaus::checkRemainBett() {
    if(aktuellBett > 0) return true;
    else {
        log("Es gibt kein Bett mehr im Krankenhaus");
        return false;
    }
}

int Krankenhaus::ZeitSimulieren(int VergehenTag) {
    if(VergehenTag <= 0) {
        log("Invalid Value");
        return 0;
    }
    for(unsigned int i{0}; i < PatList.size(); i++) {
        PatList.at(i).reduceDauer(VergehenTag);
        PatList.at(i).DiagzuGeheilt();
    }
    for(unsigned int i{0}; i < PatList.size(); i++) {
        if(PatList.at(i).getPatientenDiagnose() == geheilt) {
            PatList.erase(PatList.begin() + i);
            aktuellBett++;
            i--;
        }
    }
        checkPatList();
        return 0;
}
int Krankenhaus::AddPatient(Patienten & pat1, int number) {
    if(number <= 0) return 0;
    for(int i = 0; i < number ; i++) {
            pat1.setName();       //random name
            pat1.setPatientenGeburtsdatum();        //random geburtsdatum
            pat1.setDiag();         //random Diagnose
            pat1.PrintAllInfo();
            if(checkRemainBett()) {         //check if we still have bed in Hospital
            pat1.setPatientenNummer();
            addPatienten(pat1);

        }
    }
    return 0;
}
