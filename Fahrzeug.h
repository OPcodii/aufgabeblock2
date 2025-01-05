#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <iostream>
#include <memory>
#include <string>
#include "Simulationsobjekt.h"
#include "Verhalten.h"

class Weg;
class Fahrzeug : public Simulationsobjekt {
private:
	    std::unique_ptr<Verhalten> p_pVerhalten;
protected:
    double p_dAbschnittStrecke = 0.0;
    double p_dMaxGeschwindigkeit = 0.0; // Maximum speed (km/h)
    double p_dGesamtStrecke = 0.0;      // Total distance traveled (km)
    double p_dGesamtZeit =0.0;
public:
    // Constructors
    Fahrzeug(const std::string& sName, double dMaxGeschwindigkeit);
    Fahrzeug(const std::string& sName);
    Fahrzeug();

    double getAbschnittStrecke() const;

   void vNeueStrecke(Weg& rWeg);
    // Getter for maximum speed
    double getMaxGeschwindigkeit() const;

    const Verhalten& getVerhalten() const;
    // Getter for total distance traveled
    double getGesamtStrecke() const;

    // Speed calculation function
    virtual double dGeschwindigkeit() const ;

    // Overloaded less-than operator for comparison
    bool operator<(const Fahrzeug& f) const;

    // Simulation function
    virtual void vSimulieren() override;

    // Output function
    void vAusgeben(std::ostream& stream = std::cout) const override;

    // Static header function
    static void vKopf(std::ostream& stream = std::cout);

    // Prevent copying
    Fahrzeug(const Fahrzeug&) = delete;
    Fahrzeug& operator=(const Fahrzeug&) = delete;
    bool operator==(const Fahrzeug& other) const;
};

#endif // FAHRZEUG_H
