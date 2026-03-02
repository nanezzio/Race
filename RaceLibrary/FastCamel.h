#ifndef FASTCAMEL_H
#define FASTCAMEL_H

#include "GroundVehicle.h"

class RACE_API FastCamel : public GroundVehicle {
public:
    FastCamel();
    VehicleName getVehicleName() const override;
protected:
    double getRestDuration(int restCount) const override;
};

#endif