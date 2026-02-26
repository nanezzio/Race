#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Types.h"
#include "RaceLibrary.h"

class RACE_API Vehicle {
public:
    Vehicle(const std::string& name, double speed, VehicleType type);
    virtual ~Vehicle() = default;

    virtual double calculateTime(double distance) const = 0;
    virtual VehicleName getVehicleName() const = 0;

    std::string getName() const { return name_; }
    VehicleType getType() const { return type_; }
    double getSpeed() const { return speed_; }

protected:
    std::string name_;
    double speed_;
    VehicleType type_;
};

#endif