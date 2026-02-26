#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirVehicle("Ковёр-самолёт", 10) {}

double MagicCarpet::getDistanceCoefficient(double distance) const {
    if (distance < 1000) return 1.0;
    if (distance < 5000) return 0.97;
    if (distance < 10000) return 0.9;
    return 0.95;
}

VehicleName MagicCarpet::getVehicleName() const {
    return VehicleName::MagicCarpet;
}