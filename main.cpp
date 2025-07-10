#include "RocketSimulator.hpp"
#include <fstream>
#include <iostream>

int main() {
    RocketStage stage(
        5000,   // thrust (N)
        10,     // burn time (s)
        100,    // fuel mass (kg)
        50,     // dry mass (kg)
        250     // isp (s)
    );

    double dt = 0.1;
    RocketSimulator sim(stage, dt);

    std::ofstream file("output.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open output file (output.csv)\n";
        return 1;
    }

    sim.run_simulation(file);
    std::cout << "Simulation complete. Data written to output.csv\n";
    return 0;
}
