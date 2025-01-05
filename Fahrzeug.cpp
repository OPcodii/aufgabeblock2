#include <iostream>
#include <iomanip>
#include "Fahrzeug.h"
#include "Fahren.h" // Include behavior classes
#include "Parken.h"

// Global variable for simulation time
extern double dGlobaleZeit;

// Constructor with name and maximum speed
Fahrzeug::Fahrzeug(const std::string& sName, double dMaxGeschwindigkeit)
    : Simulationsobjekt(sName),
      p_pVerhalten(nullptr), // Matches declaration order
      p_dAbschnittStrecke(0.0),
      p_dMaxGeschwindigkeit(dMaxGeschwindigkeit),
      p_dGesamtStrecke(0.0),
      p_dGesamtZeit(0.0) {
    std::cout << "Fahrzeug \"" << sName << "\" mit Maximalgeschwindigkeit " << dMaxGeschwindigkeit << " wurde erstellt.\n";
}

// Constructor with only a name
Fahrzeug::Fahrzeug(const std::string& sName)
    : Simulationsobjekt(sName),
      p_pVerhalten(nullptr), // Matches declaration order
      p_dAbschnittStrecke(0.0),
      p_dMaxGeschwindigkeit(0.0),
      p_dGesamtStrecke(0.0),
      p_dGesamtZeit(0.0) {
    std::cout << "Fahrzeug \"" << sName << "\" wurde erstellt.\n";
}

// Default constructor
Fahrzeug::Fahrzeug()
    : Simulationsobjekt(),
      p_pVerhalten(nullptr), // Matches declaration order
      p_dAbschnittStrecke(0.0),
      p_dMaxGeschwindigkeit(0.0),
      p_dGesamtStrecke(0.0),
      p_dGesamtZeit(0.0) {
    std::cout << "Fahrzeug ohne Name wurde erstellt.\n";
}

// Getter for section distance
double Fahrzeug::getAbschnittStrecke() const {
    return p_dAbschnittStrecke;
}

// Getter for maximum speed
double Fahrzeug::getMaxGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit;
}

// Getter for total distance traveled
double Fahrzeug::getGesamtStrecke() const {
    return p_dGesamtStrecke;
}

// Speed calculation function
double Fahrzeug::dGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit; // Default: returns maximum speed
}

// Simulation function
void Fahrzeug::vSimulieren() {
    if (p_dZeit >= dGlobaleZeit) {
        return; // Already simulated for the current time step
    }

    double dVergangeneZeit = dGlobaleZeit - p_dZeit; // Time elapsed since the last simulation step

    if (p_pVerhalten) {
        // If Verhalten is set, use its logic to calculate the distance
        double dFahrstrecke = p_pVerhalten->dStrecke(*this, dVergangeneZeit);
        p_dAbschnittStrecke += dFahrstrecke; // Update section-specific distance
        p_dGesamtStrecke += dFahrstrecke;    // Update total distance traveled
    } else {
        // Fallback to original logic if Verhalten is not set
        p_dGesamtStrecke += dVergangeneZeit * dGeschwindigkeit();
    }

    p_dZeit = dGlobaleZeit; // Update the last simulation time
}


// Assign a new road for the vehicle
void Fahrzeug::vNeueStrecke(Weg& rWeg) {
        p_pVerhalten = std::make_unique<Fahren>(rWeg);
    p_dAbschnittStrecke = 0.0; // Reset section distance
}

// Less-than operator for comparison
bool Fahrzeug::operator<(const Fahrzeug& fahrzeug) const {
    return p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke;
}
bool Fahrzeug::operator==(const Fahrzeug& other) const {
        return this->getName() == other.getName(); // Compare Fahrzeug by name
    }
    const Verhalten& Fahrzeug::getVerhalten() const {
        return *p_pVerhalten;
    }

// Output header
void Fahrzeug::vKopf(std::ostream& stream) {
    stream << std::setw(10) << std::setiosflags(std::ios::left) << "ID";
    stream << std::setw(20) << std::setiosflags(std::ios::left) << "Name";
    stream << std::setw(20) << std::setiosflags(std::ios::left) << "MaxGeschwindigkeit";
    stream << std::setw(20) << std::setiosflags(std::ios::left) << "GesamtStrecke";
    stream << std::setw(20) << std::setiosflags(std::ios::left) << "Verbrauch (L)";
    stream << std::setw(20) << std::setiosflags(std::ios::left) << "Tankinhalt (L)";
    stream << std::endl;
    stream << std::string(110, '-') << std::endl;
}

// Output function
void Fahrzeug::vAusgeben(std::ostream& stream) const {
	       Simulationsobjekt::vAusgeben(stream);
           stream<< std::setw(20) << std::left << p_dMaxGeschwindigkeit;
           stream<< std::setw(20) << std::left << p_dGesamtStrecke;
}
