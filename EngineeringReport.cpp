#include "EngineeringReport.hpp"
#include <iostream>

constexpr inline double GRAVITY = 9.81;

void print_engineering_report(const RocketStage& stage, double payload) {
    double m0 = stage.dry_mass + stage.fuel_mass;
    double mf = m0 - stage.fuel_mass;
    double burn_time = stage.burn_time;
    double isp = stage.isp;
    double g0 = GRAVITY;
    double c = isp * g0;
    double propellant_mass = stage.fuel_mass;
    double mdot = propellant_mass / burn_time;
    double thrust = mdot * c;
    double total_impulse = thrust * burn_time;

    std::cout << "--- Engineering Analysis ---\n";
    std::cout << "Initial mass (m0): " << m0 << " kg\n";
    std::cout << "Final mass (mf): " << mf << " kg\n";
    std::cout << "Payload: " << payload << " kg\n";
    std::cout << "Effective exhaust velocity (c): " << c << " m/s\n";
    std::cout << "Mass flow rate: " << mdot << " kg/s\n";
    std::cout << "Thrust: " << thrust << " N\n";
    std::cout << "Total impulse: " << total_impulse << " N·s\n";

    double MR_vehicle = mf / m0;
    double MR_propulsion = (mf - payload) / (m0 - payload);
    double zeta = propellant_mass / (m0 - payload);
    double impulse_to_weight = total_impulse / ((m0 - payload) * g0);
    double max_acceleration = thrust / mf;
    double max_accel_g = max_acceleration / g0;

    std::cout << "Vehicle mass ratio: " << MR_vehicle << "\n";
    std::cout << "Propulsion unit mass ratio: " << MR_propulsion << "\n";
    std::cout << "Propellant mass fraction: " << zeta << "\n";
    std::cout << "Impulse-to-weight ratio: " << impulse_to_weight << " sec\n";
    std::cout << "Max acceleration: " << max_acceleration << " m/s² (" << max_accel_g << " g0)\n";

    if (max_accel_g > 35.0)
        std::cout << "⚠️  WARNING: Max acceleration exceeds 35g0 limit!\n";

    std::cout << "----------------------------\n\n";
}
