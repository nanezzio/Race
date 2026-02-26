#include "GroundVehicle.h"

GroundVehicle::GroundVehicle(const std::string& name, double speed, double moveTimeBeforeRest)
    : Vehicle(name, speed, VehicleType::Ground), moveTimeBeforeRest_(moveTimeBeforeRest) {
}

double GroundVehicle::calculateTime(double distance) const {
    double totalTime = 0.0;
    double remainingDist = distance;
    int restCount = 0;

    while (remainingDist > 0) {
        double distOnCurrentMove = speed_ * moveTimeBeforeRest_;
        if (remainingDist <= distOnCurrentMove) {
            totalTime += remainingDist / speed_;
            break;
        }
        else {
            totalTime += moveTimeBeforeRest_;
            remainingDist -= distOnCurrentMove;
            totalTime += getRestDuration(restCount);
            ++restCount;
        }
    }
    return totalTime;
}