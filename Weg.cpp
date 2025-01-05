#include "Weg.h"
#include "Fahrzeug.h" // Include full definition of Fahrzeug
#include <iomanip>
#include <limits>
#include <list>
#include <memory>
// Default constructor
Weg::Weg()
    : Simulationsobjekt(""), p_dLaenge(0.0), p_eTempolimit(Tempolimit::Autobahn) {}

// Constructor with parameters
Weg::Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit)
    : Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit) {}

// Getter for road length
double Weg::getLaenge() const {
    return p_dLaenge;
}

// Getter for speed limit
double Weg::getTempolimit() const {
    switch (p_eTempolimit) {
        case Tempolimit::Innerorts:
            return 50.0;
        case Tempolimit::Landstrasse:
            return 100.0;
        case Tempolimit::Autobahn:
            return std::numeric_limits<double>::infinity(); // No limit
    }
    return 0.0; // Default, just in case (should not happen)
}


// Simulation function
void Weg::vSimulieren() {
    for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end();) {
        auto& fahrzeug = **it;

        try {
            fahrzeug.vSimulieren();

            if (fahrzeug.getAbschnittStrecke() >= p_dLaenge) {
                throw Streckenende(fahrzeug, *this);
            }

            ++it;
        } catch (const Fahrausnahme& ex) {
            ex.vBearbeiten();
            it = p_pFahrzeuge.erase(it); // Remove the vehicle if necessary
        }
    }
}




// Accept a vehicle onto the road
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFzg) {
	 // Move the Fahrzeug into the list
	    p_pFahrzeuge.push_back(std::move(pFzg));

	    std::cout << "Added Fahrzeug: " << p_pFahrzeuge.back()->getName() << " to Weg: " << getName() << "\n";
	    auto& fahrzeug = *(p_pFahrzeuge.back());
	    fahrzeug.vNeueStrecke(*this);
}
std::unique_ptr<Fahrzeug> Weg::pvAbgabe(const Fahrzeug& fahrzeug) {
    for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it) {
        // Ensure the unique_ptr is valid and compare with fahrzeug
        if (*it && **it == fahrzeug) {
            // Move the Fahrzeug to a local unique_ptr
            std::unique_ptr<Fahrzeug> pFahrzeug = std::move(*it);

            // Erase the iterator and return the moved Fahrzeug
            p_pFahrzeuge.erase(it);
            return pFahrzeug;
        }
    }

    // Return nullptr if the Fahrzeug is not found
    return nullptr;
}



// Output header function
void Weg::vKopf(std::ostream& o) {
    o << std::setw(10) << std::left << "ID"
           << std::setw(20) << std::left << "Name"
           << std::setw(20) << std::left << "Length"
           << std::setw(20) << std::left << "SpeedLimit"
           << std::setw(20) << std::left << "Vehicles"
           << "\n"
           << std::string(90, '-') << "\n";
}

// Output function
void Weg::vAusgeben(std::ostream& stream) const {
    Simulationsobjekt::vAusgeben(stream);
           stream<< std::setw(20) << std::left << p_dLaenge;
           stream << std::setw(20) << std::left
  << (getTempolimit() == std::numeric_limits<double>::infinity() ? "∞" : std::to_string(getTempolimit()));


    if (p_pFahrzeuge.empty()) {
        stream <<"Keine Autos";
    }else{
        for (const auto& fahrzeug : p_pFahrzeuge) {
                stream << fahrzeug->getName() << " ";
            }
        }
}
