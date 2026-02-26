#ifndef MAGICCARPET_H
#define MAGICCARPET_H

#include "AirVehicle.h"

class RACE_API MagicCarpet : public AirVehicle {
public:
    MagicCarpet();
    virtual VehicleName getVehicleName() const override;
protected:
    virtual double getDistanceCoefficient(double distance) const override;
};

#endif