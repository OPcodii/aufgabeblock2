#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg)
    : Fahrausnahme(fahrzeug, weg) {}

void Losfahren::vBearbeiten() const {
    std::cout << "Exception: Losfahren\n";
    std::cout << "Fahrzeug: " << p_rFahrzeug.getName() << "\n";
    std::cout << "Weg: " << p_rWeg.getName() << "\n";
}
