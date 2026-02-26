#ifndef BOOTS_H
#define BOOTS_H

#include "GroundVehicle.h"

class RACE_API Boots : public GroundVehicle {
public:
    Boots();
    virtual VehicleName getVehicleName() const override;
protected:
    virtual double getRestDuration(int restCount) const override;
};

#endif