#include "EngineeringReport.hpp"
#include <iostream>

constexpr double GRAVITY = 9.81;

void print_engineering_report(const RocketStage& stage,
                              const RocketState& state,
                              double payload) {
    double m0 = stage.dry_mass + stage.fuel_mass;
    double mf = state.mass;  // initial_state.mass = m0 unless analyzing mid-flight
    double burn_time = stage.burn_time;
    double isp = stage.isp;
    double c = isp * GRAVITY;
    double mdot = state.mass_flow_rate;
    double thrust = state.thrust;
    double total_impulse = thrust * burn_time;
    double propellant_mass = stage.fuel_mass;

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
    double impulse_to_weight = total_impulse / ((m0 - payload) * GRAVITY);
    double max_acceleration = thrust / mf;
    double max_accel_g = max_acceleration / GRAVITY;

    std::cout << "Vehicle mass ratio: " << MR_vehicle << "\n";
    std::cout << "Propulsion unit mass ratio: " << MR_propulsion << "\n";
    std::cout << "Propellant mass fraction: " << zeta << "\n";
    std::cout << "Impulse-to-weight ratio: " << impulse_to_weight << " sec\n";
    std::cout << "Max acceleration: " << max_acceleration << " m/s² (" << max_accel_g << " g0)\n";

    if (max_accel_g > 35.0)
        std::cout << "⚠️  WARNING: Max acceleration exceeds 35g0 limit!\n";

    std::cout << "----------------------------\n\n";
}
