#include "AirVehicle.h"

AirVehicle::AirVehicle(const std::string& name, double speed)
    : Vehicle(name, speed, VehicleType::Air) {
}

double AirVehicle::calculateTime(double distance) const {
    double coef = getDistanceCoefficient(distance);
    double reducedDistance = distance * coef;
    return reducedDistance / speed_;
}