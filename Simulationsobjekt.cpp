#include <iostream>
#include <iomanip>
#include "Simulationsobjekt.h"

// Initialize the static variable
int Simulationsobjekt::p_iMaxID = 0;

// Constructor with name
Simulationsobjekt::Simulationsobjekt(const std::string& sName) : p_iID(++p_iMaxID), p_sName(sName) , p_dZeit(){
    std::cout << "Simulationsobjekt \"" << p_sName << "\" mit ID " << p_iID << " erstellt.\n";
}

// Default constructor
Simulationsobjekt::Simulationsobjekt() : p_iID(++p_iMaxID), p_sName("") ,p_dZeit() {
    std::cout << "Simulationsobjekt ohne Name mit ID " << p_iID << " erstellt.\n";
}

// Getter for ID
int Simulationsobjekt::getID() const {
    return p_iID;
}

// Getter for Name
std::string Simulationsobjekt::getName() const {
    return p_sName;
}

// Simulation function
void Simulationsobjekt::vSimulieren() {
    // Placeholder for 5.3; no logic required yet
}

// Output header
void Simulationsobjekt::vKopf(std::ostream& stream) {
    stream << std::setw(10) << std::left << "ID"
           << std::setw(20) << std::left << "Name"
           << "\n"
           << std::string(30, '-') << "\n";
}

// Output function
void Simulationsobjekt::vAusgeben(std::ostream& stream) const {
    stream << std::setw(10) << std::left << p_iID
           << std::setw(20) << std::left << p_sName;
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& stream, Simulationsobjekt& obj) {
    obj.vAusgeben(stream);
    return stream;
}
