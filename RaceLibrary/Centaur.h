#ifndef CENTAUR_H
#define CENTAUR_H

#include "GroundVehicle.h"

class RACE_API Centaur : public GroundVehicle {
public:
    Centaur();
    VehicleName getVehicleName() const override;
protected:
    double getRestDuration(int restCount) const override;
};

#endif