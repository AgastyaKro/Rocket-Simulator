#pragma once
#include "RocketStage.hpp"
#include "RocketState.hpp"
#include <fstream>

class RocketSimulator{
public:
    RocketSimulator(RocketStage stage, double dt);
    void run_simulation(std::ostream& out);
    RocketState compute_step(double& fuel_mass);
    void apply_kinematics(double acceleration);

private:
    RocketStage stage;
    double dt;
    double time;
    double position;
    double velocity;

    void log_state(std::ostream& out, const RocketState& s);

}; 