/*
 * Fahrausnahme.h
 *
 *  Created on: Jan 3, 2025
 *      Author: USER
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include <exception>
#include <iostream>
class Fahrzeug;
class Weg;
class Fahrausnahme : public std::exception {
protected:
    Fahrzeug& p_rFahrzeug;
    Weg& p_rWeg;

public:
    // Constructor to initialize Fahrzeug and Weg references
    Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg)
        : p_rFahrzeug(fahrzeug), p_rWeg(weg) {}

    // Pure virtual function to be overridden in derived classes
    virtual void vBearbeiten() const = 0;
};





#endif /* FAHRAUSNAHME_H_ */
