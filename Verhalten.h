#ifndef VERHALTEN_H
#define VERHALTEN_H

#include "Weg.h" // Include Weg header to use Weg type

class Fahrzeug; // Forward declaration of Fahrzeug

class Verhalten {
protected:
    Weg& p_rWeg; // Reference to the road

public:
    Verhalten(Weg& rWeg);
    virtual ~Verhalten() = default;

    // Pure virtual function for calculating distance
    virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;

    // Getter for the road
    const Weg& getWeg() const { return p_rWeg; }
};

#endif // VERHALTEN_H
