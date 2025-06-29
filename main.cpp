#include "RocketSimulator.hpp"
#include <fstream>
#include <iostream>

int main(){

    RocketStage stage(5000,   // thrust (N)
                      10,     // burn_time (s)
                      100,    // fuel_mass (kg)
                      50,     // dry_mass (kg)
                      250);   // isp (s) [not used yet]

    double dt = 0.1;
    RocketSimulator sim(stage, dt);

    std::fstream file("output.csv");
    if (!file){
        std::cerr << "Failed to open output file (output.csv). \n";
        return 1;
    }

    sim.run_simulation(file);
        std::cout << "Simulation complete.\n";
        return 0;


}