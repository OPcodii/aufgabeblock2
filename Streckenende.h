#ifndef STRECKENENDE_H
#define STRECKENENDE_H

#include "Fahrausnahme.h"
class Weg;
class Fahrzeug;
class Streckenende : public Fahrausnahme {
public:
    // Constructor
    Streckenende(Fahrzeug& fahrzeug, Weg& weg);

    // Override vBearbeiten to handle the exception
    void vBearbeiten() const override;
};

#endif
