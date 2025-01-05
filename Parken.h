#ifndef PARKEN_H
#define PARKEN_H

#include "Verhalten.h"
class Parken : public Verhalten {
private:
    double p_dStartzeit; // Start time when the vehicle begins moving

public:
    // Constructor to initialize parking behavior with the road and start time
    Parken(Weg& rWeg, double dStartzeit);

    // Override the dStrecke function to calculate the distance
    double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif // PARKEN_H
