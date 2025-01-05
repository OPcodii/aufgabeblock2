#include "Fahrrad.h"
#include <algorithm>
#include <cmath>

// Constructor with name and max speed
Fahrrad::Fahrrad(const std::string& sName, double dMaxGeschwindigkeit)
    : Fahrzeug(sName, dMaxGeschwindigkeit) {}

// Simulation function (inherits behavior from Fahrzeug)
void Fahrrad::vSimulieren() {
    Fahrzeug::vSimulieren();
}

// Output function (inherits behavior and extends)
void Fahrrad::vAusgeben(std::ostream& stream) const {
    Fahrzeug::vAusgeben(stream);
    stream << std::endl; // Adds a line break after Fahrzeug output
}

// Speed calculation with reduction logic
double Fahrrad::dGeschwindigkeit() const {
    double dReductionFactor = std::pow(0.9, static_cast<int>(p_dGesamtStrecke / 20.0));
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * dReductionFactor;
    return std::max(dAktuelleGeschwindigkeit, 12.0); // Ensure minimum speed is 12 km/h
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& stream, const Fahrzeug& fahrzeug) {
    fahrzeug.vAusgeben(stream);
    return stream;
}
