#ifndef CAMEL_H
#define CAMEL_H

#include "GroundVehicle.h"

class RACE_API Camel : public GroundVehicle {
public:
    Camel();
    virtual VehicleName getVehicleName() const override;
protected:
    virtual double getRestDuration(int restCount) const override;
};

#endif