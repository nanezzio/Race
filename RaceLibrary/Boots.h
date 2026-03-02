#ifndef BOOTS_H
#define BOOTS_H

#include "GroundVehicle.h"

class RACE_API Boots : public GroundVehicle {
public:
    Boots();
    VehicleName getVehicleName() const override;
protected:
    double getRestDuration(int restCount) const override;
};

#endif