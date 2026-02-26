#include "Boots.h"

Boots::Boots() : GroundVehicle("Ботинки-вездеходы", 6, 60) {}

double Boots::getRestDuration(int restCount) const {
    return (restCount == 0) ? 10 : 5;
}

VehicleName Boots::getVehicleName() const {
    return VehicleName::Boots;
}