#ifndef LOSFAHREN_H
#define LOSFAHREN_H

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {
public:
    // Constructor
    Losfahren(Fahrzeug& fahrzeug, Weg& weg);

    // Override vBearbeiten to handle the exception
    void vBearbeiten() const override;
};

#endif
