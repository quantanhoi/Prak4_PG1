#include "test.h"

void func() {
    log("Sup");
}
int AddPatient(Patienten& pat1, Krankenhaus& kh1, int number) {
    if(number <= 0) return 0;
    for(int i = 0; i < number ; i++) {
            pat1.setName();       //random name
            pat1.setGeburt();        //random geburtsdatum
            pat1.setDiag();         //random Diagnose
            pat1.PrintAllInfo();
            if(kh1.checkRemainBett()) {         //check if we still have bed in Hospital
            pat1.setPatientennummer();
            kh1.addPatienten(pat1);

        }
    }
    return 0;
}
