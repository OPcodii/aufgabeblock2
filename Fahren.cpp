#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <algorithm>
// For std::min
Fahren::Fahren(Weg& rWeg): Verhalten(rWeg){}
// Calculate the distance the vehicle can travel within the given time interval
double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
    // Maximum distance the vehicle can travel based on its speed and time interval
    double dMaxStrecke = aFzg.dGeschwindigkeit() * dZeitIntervall;

    // Remaining distance on the road
    double dRestWeg = p_rWeg.getLaenge() - aFzg.getAbschnittStrecke();

    // Return the smaller value between the maximum distance and the remaining road distance
    return std::min(dMaxStrecke, dRestWeg);
}
