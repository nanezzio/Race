#include "Centaur.h"

Centaur::Centaur() : GroundVehicle("Кентавр", 15, 8) {}

double Centaur::getRestDuration(int restCount) const {
    return 2; 
}

VehicleName Centaur::getVehicleName() const {
    return VehicleName::Centaur;
}