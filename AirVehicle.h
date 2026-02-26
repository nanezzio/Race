#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include "Vehicle.h"

class RACE_API AirVehicle : public Vehicle {
public:
    AirVehicle(const std::string& name, double speed);
    virtual double calculateTime(double distance) const override final;

protected:
    virtual double getDistanceCoefficient(double distance) const = 0;
};

#endif