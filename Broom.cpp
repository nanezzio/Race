#include "Broom.h"

Broom::Broom() : AirVehicle("Метла", 20) {}

double Broom::getDistanceCoefficient(double distance) const {
    int percent = static_cast<int>(distance) / 1000;
    return 1.0 - percent / 100.0;
}

VehicleName Broom::getVehicleName() const {
    return VehicleName::Broom;
}