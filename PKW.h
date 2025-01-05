#ifndef PKW_H
#define PKW_H

#include <string>
#include <limits>
#include "Fahrzeug.h"

class PKW : public Fahrzeug {
protected:
    double p_dVerbrauch;     // Fuel consumption per 100 km (in liters)
    double p_dTankvolumen;   // Tank volume (in liters)
    double p_dTankinhalt;    // Current fuel level (in liters)

public:
    // Constructor with parameters
    PKW(
        const std::string& name,
        double maxGeschwindigkeit,
        double verbrauch,
        double tankvolumen = 55.0
    );

    // Default constructor
    PKW();

    // Getter for current fuel level
    double getTankinhalt() const;

    // Overridden simulation function
    virtual void vSimulieren() override;

    // Overridden speed function
    double dGeschwindigkeit() const override;

    // Overridden refueling function
    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

    // Output functions
    static void vKopf(std::ostream& stream = std::cout);
    void vAusgeben(std::ostream& stream = std::cout) const override;
};

#endif // PKW_H
