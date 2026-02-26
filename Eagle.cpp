#include "Eagle.h"

Eagle::Eagle() : AirVehicle("Орёл", 8) {}

double Eagle::getDistanceCoefficient(double distance) const {
    return 0.94;
}

VehicleName Eagle::getVehicleName() const {
    return VehicleName::Eagle;
}