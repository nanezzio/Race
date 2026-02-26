#ifndef GROUNDVEHICLE_H
#define GROUNDVEHICLE_H

#include "Vehicle.h"

class RACE_API GroundVehicle : public Vehicle {
public:
    GroundVehicle(const std::string& name, double speed, double moveTimeBeforeRest);
    virtual double calculateTime(double distance) const override final;

protected:
    virtual double getRestDuration(int restCount) const = 0;

private:
    double moveTimeBeforeRest_;
};

#endif