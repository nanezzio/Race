#ifndef CAMEL_H
#define CAMEL_H

#include "GroundVehicle.h"

class RACE_API Camel : public GroundVehicle {
public:
    Camel();
    VehicleName getVehicleName() const override;
protected:
    double getRestDuration(int restCount) const override;
};

#endif