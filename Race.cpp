#include "Race.h"
#include <algorithm>

Race::Race(RaceType type, double distance) : raceType_(type), distance_(distance) {}

Race::~Race() {
    for (auto v : participants_) delete v;
}

bool Race::addVehicle(Vehicle* vehicle) {
    if (!vehicle) return false;

    if (raceType_ == RaceType::GroundOnly && vehicle->getType() != VehicleType::Ground)
        return false;
    if (raceType_ == RaceType::AirOnly && vehicle->getType() != VehicleType::Air)
        return false;

    int idx = static_cast<int>(vehicle->getVehicleName());
    if (registered_[idx]) return false;

    registered_[idx] = true;
    participants_.push_back(vehicle);
    return true;
}

bool Race::canStart() const {
    return participants_.size() >= 2;
}

std::vector<std::pair<Vehicle*, double>> Race::runRace() const {
    std::vector<std::pair<Vehicle*, double>> results;
    results.reserve(participants_.size());

    for (auto v : participants_) {
        results.emplace_back(v, v->calculateTime(distance_));
    }

    for (size_t i = 0; i + 1 < results.size(); ++i) {
        for (size_t j = 0; j + 1 < results.size() - i; ++j) {
            if (results[j].second > results[j + 1].second) {
                auto temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
    return results;
}