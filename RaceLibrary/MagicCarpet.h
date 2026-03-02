#ifndef MAGICCARPET_H
#define MAGICCARPET_H

#include "AirVehicle.h"

class RACE_API MagicCarpet : public AirVehicle {
public:
    MagicCarpet();
    VehicleName getVehicleName() const override;
protected:
    double getDistanceCoefficient(double distance) const override;
};

#endif