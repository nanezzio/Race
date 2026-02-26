#include <vector>
#include "Types.h"
#include "Vehicle.h"
#include "RaceLibrary.h"

class RACE_API Race {
public:
    Race(RaceType type, double distance);
    ~Race(); 

    bool addVehicle(Vehicle* vehicle); 
    bool canStart() const;
    std::vector<std::pair<Vehicle*, double>> runRace() const;

    double getDistance() const { return distance_; }
    RaceType getRaceType() const { return raceType_; }
    const std::vector<Vehicle*>& getParticipants() const { return participants_; }

private:
    RaceType raceType_;
    double distance_;
    std::vector<Vehicle*> participants_;
    bool registered_[7] = { false }; 
};