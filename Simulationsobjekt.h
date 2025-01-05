#ifndef SIMULATIONSOBJEKT_H
#define SIMULATIONSOBJEKT_H

#include <iostream>
#include <string>
#include "Global.h"
class Simulationsobjekt {
private:
    static int p_iMaxID; // Static variable for unique ID assignment

protected:
    int p_iID;           // Unique ID of the object
    std::string p_sName; // Name of the object
    double p_dZeit;      // Last simulation time

public:
    // Constructors
    Simulationsobjekt(const std::string& sName);
    Simulationsobjekt();
    virtual ~Simulationsobjekt() = default;

    // Getter methods
    int getID() const;
    std::string getName() const;

    // Pure virtual method for simulation
    virtual void vSimulieren() = 0;

    // Prevent copying
    Simulationsobjekt(const Simulationsobjekt&) = delete;
    Simulationsobjekt& operator=(const Simulationsobjekt&) = delete;

    // Output function
    virtual void vAusgeben(std::ostream& stream = std::cout) const = 0;

    // Static header function for output formatting
   static void vKopf(std::ostream& stream = std::cout);
};

// Operator to output a `Simulationsobjekt` to a stream
std::ostream& operator<<(std::ostream& stream, Simulationsobjekt& obj);

#endif // SIMULATIONSOBJEKT_H
