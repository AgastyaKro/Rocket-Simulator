#pragma once
#include "RocketStage.hpp"
#include <fstream>

class RocketSimulator{
public:
    RocketSimulator(RocketStage stage, double dt);
    void run_simulation(std::ostream& out);

private:
    RocketStage stage;
    double dt;
    double time;
    double position;
    double velocity;

    void log_state(std::ostream& out, double mass, double acceleration);

};