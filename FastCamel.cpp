#include "FastCamel.h"

FastCamel::FastCamel() : GroundVehicle("Верблюд-быстроход", 40, 10) {}

double FastCamel::getRestDuration(int restCount) const {
    if (restCount == 0) return 5;
    if (restCount == 1) return 6.5;
    return 8;
}

VehicleName FastCamel::getVehicleName() const {
    return VehicleName::FastCamel;
}