#ifndef EAGLE_H
#define EAGLE_H

#include "AirVehicle.h"

class RACE_API Eagle : public AirVehicle {
public:
    Eagle();
    virtual VehicleName getVehicleName() const override;
protected:
    virtual double getDistanceCoefficient(double distance) const override;
};

#endif