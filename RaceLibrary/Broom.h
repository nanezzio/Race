#ifndef BROOM_H
#define BROOM_H

#include "AirVehicle.h"

class RACE_API Broom : public AirVehicle {
public:
    Broom();
    VehicleName getVehicleName() const override;
protected:
    double getDistanceCoefficient(double distance) const override;
};

#endif