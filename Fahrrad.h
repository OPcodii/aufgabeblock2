#ifndef FAHRRAD_H
#define FAHRRAD_H

#include <string>
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
    // Constructor with name and max speed
    Fahrrad(const std::string& sName, double dMaxGeschwindigkeit);

    // Default constructor
    Fahrrad();
    void vSimulieren() override;
    // Speed calculation function (overrides Fahrzeug)
    double dGeschwindigkeit() const override;

    // Output functions
    virtual void vAusgeben(std::ostream& stream = std::cout) const override;
};

#endif // FAHRRAD_H
