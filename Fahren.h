#ifndef FAHREN_H
#define FAHREN_H

#include "Verhalten.h"

class Fahren : public Verhalten {
public:

    Fahren(Weg& rWeg);
    double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif
