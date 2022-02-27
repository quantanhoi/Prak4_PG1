#include"main.h"
int main() {
    srand(time(NULL));
    Patienten pat1;
    Krankenhaus kh1;

    char choice{};
    int number{};
    while(choice != '4') {
        cout << "1. Add Patient\n2. Zeit Simulieren\n3. Check Patient List\n4. Quit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "How many patient do you want to add?: ";
                cin >> number;
                kh1.AddPatient(pat1, number);
                kh1.checkPatList();
            break;
        case '2':
            int VergehenTag;
            log("Wie viele Tage haben vergangen? ");
            cin >> VergehenTag;
            kh1.ZeitSimulieren(VergehenTag);
            break;
        case '3':
            kh1.checkPatList();
            break;
        default:
            break;
        }
    }
}

