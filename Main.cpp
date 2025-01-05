#include <iostream>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include <memory>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "Weg.h"
#include "Simulationsobjekt.h"
#include "Weg.cpp"

void vAufgabe_4() {
    // Erzeugen eines Wege
    Weg weg1("Autobahn A1", 100.0, Tempolimit::Innerorts);

    // Ausgabe des Weges
    Weg::vKopf();
    std::cout << weg1 << std::endl;
}

void vAufgabe_5(){
    // Output start message
    std::cout << "Starting the simulation of the Verkehrsnetz...\n";

    // Setup: Create Wege and Fahrzeuge
    Weg landstrasse("Landstraße", 100.0);

    auto bmw = std::make_unique<PKW>("BMW", 120, 8.0);
    auto audi = std::make_unique<PKW>("Audi", 150, 7.5);
    auto bike = std::make_unique<Fahrrad>("BMX", 30);

    // Add Fahrzeuge to the Weg
    landstrasse.vAnnahme(std::move(bmw));
    landstrasse.vAnnahme(std::move(audi));
    landstrasse.vAnnahme(std::move(bike));
    Weg::vKopf();
    // Simulate the Weg over several time steps
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 10.0; dGlobaleZeit += 1.0) {
        std::cout << "Simulation Step: " << dGlobaleZeit << "\n";

        // Print the header
        // Simulate the Weg
        landstrasse.vAusgeben(std::cout);
        landstrasse.vSimulieren();

        // Output the current state of the Weg and its Fahrzeuge
        landstrasse.vAusgeben(std::cout);

        std::cout << "\n";
    }
}
void vAufgabe_6() {
    std::cout << "Starting exception and Tempolimit test...\n";

    // Create two roads (one with Tempolimit)
    Weg landstrasse("Landstraße", 100.0, Tempolimit::Innerorts); // Tempolimit: 50 km/h
    Weg autobahn("Autobahn", 500.0, Tempolimit::Autobahn);       // No Tempolimit

    // Create vehicles
    auto bmw = std::make_unique<PKW>("BMW", 120, 8.0); // Max speed: 120 km/h
    auto audi = std::make_unique<PKW>("Audi", 150, 7.5); // Max speed: 150 km/h
    auto bike = std::make_unique<Fahrrad>("BMX", 30);    // Max speed: 30 km/h

    // Assign vehicles to roads
    landstrasse.vAnnahme(std::move(bmw));
    landstrasse.vAnnahme(std::move(audi));
    autobahn.vAnnahme(std::move(bike));

    // Simulate the roads for several time steps
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 6.0; dGlobaleZeit += 0.25) {
        std::cout << "\nSimulation Step: " << dGlobaleZeit << "\n";
        Weg::vKopf();

        try {
            landstrasse.vSimulieren();
            autobahn.vSimulieren();
        } catch (const Fahrausnahme& ex) {
            ex.vBearbeiten(); // Handle exceptions
        }
    }
}





void vAufgabe1() {
    Fahrzeug f1("BMW", 150);
    Fahrzeug f2("Benz", 120);
    cout << "Fahrzeug Objekte wurden erstellt" << endl;

    Fahrzeug* Car1 = new Fahrzeug("Honda", 120);
    Fahrzeug* Car2 = new Fahrzeug("Toyota", 100);

    cout << "2 neue Fahrzeuge wurden erstellt: " << Car1->getName() << " " << Car2->getName() << endl;

    delete Car1;
    delete Car2;
    cout << "Die Fahrzeuge wurden jetzt gelöscht" << endl;

    auto Fahrzeug1 = make_unique<Fahrzeug>("Nissan", 120);
    auto Fahrzeug2 = make_shared<Fahrzeug>("Skoda", 180);
    auto Fahrzeug3 = Fahrzeug2;
    cout << "Die Zahl der Shared Pointer in Fahrzeug2 bevor wir reset Funktion nutzen: "
         << Fahrzeug2.use_count() << endl;
    Fahrzeug2.reset();
    cout << "Die Zahl der Shared Pointer in Fahrzeug2 nach reset: "
         << Fahrzeug2.use_count() << endl;
    cout << "Jetzt machen wir einen Vector und fügen ein unique_ptr dazu mit push_back Funktion" << endl;
    vector<unique_ptr<Fahrzeug>> Cars;
    Cars.push_back(move(Fahrzeug1));
    cout << "Jetzt enthält der Vector den unique_ptr an der letzten Position" << endl;
    for (const auto& fahrzeug : Cars) {
        cout << "Fahrzeug: " << fahrzeug->getName() << endl;
    }
    Cars.clear();
    cout << "Jetzt sollte der Cars Vector leer sein nach Nutzung von clear() Funktion" << endl;
}

void vAufgabe1a() {
    vector<unique_ptr<Fahrzeug>> Fahrzeuge;
    for (int i = 0; i < 3; i++) {
        string name;
        double MaxGeschwindigkeit;
        cout << "Geben Sie bitte ein Fahrzeug Name " << (i + 1) << ": ";
        cin >> name;
        cout << endl;
        cout << "Geben Sie nun bitte die max Geschwindigkeit " << (i + 1) << ": ";
        cin >> MaxGeschwindigkeit;
        cout << endl;

        Fahrzeuge.push_back(move(make_unique<Fahrzeug>(name, MaxGeschwindigkeit)));
    }
    Fahrzeug::vKopf(cout);
    dGlobaleZeit = 0.0;
    double dSimulationDauer = 5.0;
    double dZeitSchritt = 0.5;

    while (dGlobaleZeit < dSimulationDauer) {
        dGlobaleZeit += dZeitSchritt;

        for (auto& fahrzeug : Fahrzeuge) {
            fahrzeug->vSimulieren();
            fahrzeug->vAusgeben(cout);
        }
        cout << endl;
    }
}

void vAufgabe2() {
    int iPKWZahl, iFahrradZahl;
    cout << "Wieviel PKWs wollen Sie erstellen? ";
    cin >> iPKWZahl;
    cout << "Wieviel Fahrräder wollen Sie erstellen? ";
    cin >> iFahrradZahl;
    vector<unique_ptr<PKW>> PKWs;
    vector<unique_ptr<Fahrrad>> Fahrrads;
    for (int i = 0; i < iPKWZahl; i++) {
        string name;
        double MaxGeschwindigkeit, dVerbrauch;
        cout << "Was soll der PKW heißen? ";
        cin >> name;
        cout << endl;
        cout << "Was soll die max Geschwindigkeit des PKWs sein? ";
        cin >> MaxGeschwindigkeit;
        cout << endl;
        cout << "Verbrauch? (L / 100km) ";
        cin >> dVerbrauch;
        cout << endl;
        PKWs.push_back(move(make_unique<PKW>(name, MaxGeschwindigkeit, dVerbrauch)));
    }
    for (int i = 0; i < iFahrradZahl; i++) {
        string name;
        double MaxGeschwindigkeit;
        cout << "Was soll das Fahrrad heißen? ";
        cin >> name;
        cout << endl;
        cout << "Was soll die max Geschwindigkeit des Fahrrads sein? ";
        cin >> MaxGeschwindigkeit;
        cout << endl;
        Fahrrads.push_back(move(make_unique<Fahrrad>(name, MaxGeschwindigkeit)));
    }
    dGlobaleZeit = 0.0;
    double dSimulationDauer = 5.0;
    double dZeitSchritt = 0.5;

    while (dGlobaleZeit < dSimulationDauer) {
        dGlobaleZeit += dZeitSchritt;
        Fahrzeug::vKopf(cout);
        for (auto& pkw : PKWs) {
            pkw->vSimulieren();
            pkw->vAusgeben(cout);
        }
        for (auto& fahrrad : Fahrrads) {
            fahrrad->vSimulieren();
            fahrrad->vAusgeben(cout);
        }
        double dletzteTankZeit = 0.0;
        if (std::fabs(std::fmod(dGlobaleZeit, 3.0)) < 0.0001 && dGlobaleZeit - dletzteTankZeit >= 3.0) {
            for (auto& pkw : PKWs) {
                cout << pkw->getName() << " wird nach " << dGlobaleZeit << " Stunden getankt." << endl;
                pkw->dTanken(std::numeric_limits<double>::infinity());
            }
            dletzteTankZeit = dGlobaleZeit;
        }

        cout << endl;
    }
}

void vAusgabe3() {
    Fahrzeug f1("Car1", 100);
    Fahrzeug f2("Car2", 120);
    PKW p1("BMW", 150, 8.0);
    Fahrrad b1("BMX", 30);
    cout << "\nHier werden wir vAusgabe3 nutzen, um Operatoren zu testen" << endl;
    cout << "operator<<:" << endl;
    Fahrzeug::vKopf(cout);
    cout << f1 << endl;
    cout << f2 << endl;
    cout << p1 << endl;
    cout << b1 << endl;

    cout << "\nJetzt überprüfen wir den operator<:" << endl << endl;
    if (f1 < f2) {
        cout << f1.getName() << " ist weniger als " << f2.getName() << " gefahren" << endl;
    } else {
        cout << f1.getName() << " ist mehr oder gleich " << f2.getName() << " gefahren" << endl;
    }
}

int main(){
	//vAufgabe_5();
    // vAufgabe1();
     //vAufgabe1a();
   //vAufgabe2();
     //vAusgabe3();
	//vAufgabe_4();
	std::cout<<"hi";
	vAufgabe_6();

	    return 0;
}
