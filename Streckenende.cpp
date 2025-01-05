#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg)
    : Fahrausnahme(fahrzeug, weg) {}

void Streckenende::vBearbeiten() const {
    std::cout << "Exception: Streckenende\n";
    std::cout << "Fahrzeug: " << p_rFahrzeug.getName() << "\n";
    std::cout << "Weg: " << p_rWeg.getName() << "\n";
}
