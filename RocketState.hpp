#pragma once
#include "RocketStage.hpp"
#include <iostream>

// need to update this to a class
struct RocketState {
    double time;
    double position;
    double velocity;
    double mass;
    double fuel_mass;
    double thrust;
    double acceleration;
    double acceleration_g;
    double mass_flow_rate;
    double net_force;
    double weight;
    double drag = 0.0; 

    // Functions
    std::string to_csv_row() const;
};

RocketState compute_state(double time, double position, double velocity,
                          double fuel_mass, const RocketStage& stage);
