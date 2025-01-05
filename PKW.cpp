#include <iostream>
#include <iomanip>
#include "PKW.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <algorithm>

extern double dGlobaleZeit;

// Constructor with parameters
PKW::PKW(
    const std::string& name,
    double maxGeschwindigkeit,
    double verbrauch,
    double tankvolumen
) : Fahrzeug(name, maxGeschwindigkeit),
    p_dVerbrauch(verbrauch),
    p_dTankvolumen(tankvolumen),
    p_dTankinhalt(tankvolumen / 2.0) {
    std::cout << "PKW \"" << name << "\" mit Verbrauch " << p_dVerbrauch
              << " l/100km und einem Tankvolumen von " << p_dTankvolumen << " Litern wurde erstellt.\n";
}

// Default constructor
PKW::PKW() : PKW("", 0.0, 0.0, 0.0) {}

// Getter for current fuel level
double PKW::getTankinhalt() const {
    return p_dTankinhalt;
}

// Simulation function
void PKW::vSimulieren() {
	   if (p_dZeit >= dGlobaleZeit) {
	        return;
	    }

	    double dZeitSchritt = dGlobaleZeit - p_dZeit;

	    if (p_dTankinhalt > 0.0) {
	        double dVerbrauch = (dGeschwindigkeit() * dZeitSchritt / 100.0) * p_dVerbrauch;

	        if (p_dTankinhalt >= dVerbrauch) {
	            Fahrzeug::vSimulieren();
	            p_dTankinhalt -= dVerbrauch;
	        } else {
	            double dPossibleDistance = (p_dTankinhalt / p_dVerbrauch) * 100.0;
	            p_dGesamtStrecke += dPossibleDistance;

	            std::cout << getName() << " hat nur noch " << p_dTankinhalt
	                      << " Liter im Tank. Es fährt " << dPossibleDistance
	                      << " km weiter und stoppt." << std::endl;
	            p_dTankinhalt = 0.0;
	        }
	    } else {
	        std::cout << getName() << " hat keinen Kraftstoff mehr und bleibt stehen." << std::endl;
	    }

	    p_dZeit = dGlobaleZeit;
	}


// Speed calculation function
double PKW::dGeschwindigkeit() const {
    return std::min(p_dMaxGeschwindigkeit, getVerhalten().getWeg().getTempolimit());
}


// Refueling function
double PKW::dTanken(double dMenge) {
    double dGetankteMenge = std::min(dMenge, p_dTankvolumen - p_dTankinhalt);
    p_dTankinhalt += dGetankteMenge;
    return dGetankteMenge;
}

// Output header function
void PKW::vKopf(std::ostream& stream) {
    stream << std::setw(10) << std::left << "ID"
           << std::setw(20) << std::left << "Name"
           << std::setw(20) << std::left << "MaxSpeed"
           << std::setw(20) << std::left << "Tankinhalt"
           << std::setw(20) << std::left << "Consumption"
           << "\n"
           << std::string(90, '-') << "\n";
}

// Output function
void PKW::vAusgeben(std::ostream& stream) const {
    Fahrzeug::vAusgeben(stream);
    stream << std::setw(20) << std::setiosflags(std::ios::left)
              << (p_dGesamtStrecke / 100.0) * p_dVerbrauch;
    stream << std::setw(20) << std::setiosflags(std::ios::left) << p_dTankinhalt;
    stream << std::endl; // Ensure row separation
}
