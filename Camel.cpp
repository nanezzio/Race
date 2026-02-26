#include "Camel.h"

Camel::Camel() : GroundVehicle("Верблюд", 10, 30) {}

double Camel::getRestDuration(int restCount) const {
    return (restCount == 0) ? 5 : 8;
}

VehicleName Camel::getVehicleName() const {
    return VehicleName::Camel;
}