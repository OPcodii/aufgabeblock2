#include "Parken.h"
#include <iostream>
#include "Fahrzeug.h"// For std::cout if needed

// Constructor: initializes the road and start time for the parked vehicle
Parken::Parken(Weg& rWeg, double dStartzeit)
    : Verhalten(rWeg), p_dStartzeit(dStartzeit) {}

// Calculates the distance a parked vehicle can travel (always 0 if it's before the start time)
double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
    // Check if the vehicle is allowed to move
    if (dGlobaleZeit < p_dStartzeit) {
        return 0.0; // Vehicle remains stationary until the start time
    }

    // Optional: Output a message when the vehicle is ready to start moving
    std::cout << aFzg.getName() << " starts driving on " << p_rWeg.getName() << ".\n";

    // After the start time, the behavior transitions to moving logic, handled elsewhere
    return 0.0; // The `Fahren` behavior will take over once parked behavior ends
}
