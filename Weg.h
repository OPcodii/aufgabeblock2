#ifndef WEG_H
#define WEG_H

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "Simulationsobjekt.h"
#include "Fahrausnahme.h"
#include "Losfahren.h"
#include "Streckenende.h"

class Fahrzeug;

enum class Tempolimit { Innerorts, Landstrasse, Autobahn };

class Weg : public Simulationsobjekt {
private:
    double p_dLaenge;                      // Length of the road in km
    Tempolimit p_eTempolimit;              // Speed limit for the road
    std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge; // List of vehicles on the road
public:
    // Constructors
    Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);
    Weg();

    // Getter for road length
    double getLaenge() const;

    // Getter for speed limit
    double getTempolimit() const;

    // Simulation function
    virtual void vSimulieren() override;

    // Accept a vehicle onto the road
    void vAnnahme(std::unique_ptr<Fahrzeug> pFzg);

    std::unique_ptr<Fahrzeug> pvAbgabe(const Fahrzeug& fahrzeug);

    // Output function
    virtual void vAusgeben(std::ostream& stream = std::cout) const override;

    // Static header function for output formatting
    static void vKopf(std::ostream& o = std::cout);

    // Prevent copying
    Weg(const Weg&) = delete;
    Weg& operator=(const Weg&) = delete;
};

#endif // WEG_H
