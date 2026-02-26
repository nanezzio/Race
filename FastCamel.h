#ifndef FASTCAMEL_H
#define FASTCAMEL_H

#include "GroundVehicle.h"

class RACE_API FastCamel : public GroundVehicle {
public:
    FastCamel();
    virtual VehicleName getVehicleName() const override;
protected:
    virtual double getRestDuration(int restCount) const override;
};

#endif