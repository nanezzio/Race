#ifndef EAGLE_H
#define EAGLE_H

#include "AirVehicle.h"

class RACE_API Eagle : public AirVehicle {
public:
    Eagle();
    VehicleName getVehicleName() const override;
protected:
    double getDistanceCoefficient(double distance) const override;
};

#endif