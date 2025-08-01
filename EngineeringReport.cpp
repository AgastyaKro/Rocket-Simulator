#include "EngineeringReport.hpp"
#include "Constants.hpp"
#include "Environment.hpp"
#include <iostream>

// Compute metrics
EngineeringMetrics compute_engineering_metrics(const RocketStage& RocketStage_,
                                              const RocketState& RocketState_,
                                              double payload){
    EngineeringMetrics m{};
    Environment EnvObject;

    const double m0 = RocketStage_.dry_mass + RocketStage_.fuel_mass;
    const double mf = RocketState_.mass;               // after burn (initial_state == t0 -> mf == m0)
    const double c  = RocketStage_.isp * GRAVITY;            // exhaust velocity
    const double mdot = RocketState_.mass_flow_rate;
    const double total_impulse = RocketState_.thrust * RocketStage_.burn_time;

    m.MR_vehicle               = mf / m0;
    m.MR_propulsion            = (mf - payload) / (m0 - payload);
    m.propellant_mass_fraction = RocketStage_.fuel_mass / (m0 - payload);
    m.exhaust_velocity         = c; // also know as v2 in the book (velocity of gas leaving nozzle)
    m.mass_flow_rate           = mdot;
    m.thrust                   = mdot * c + (RocketStage_.nozzle_gas_pressure-EnvObject.getEnvPressure()) * RocketStage_.nozzle_exit_area;
    m.total_impulse            = total_impulse;
    m.impulse_to_weight_ratio  = total_impulse / ((m0 - payload) * GRAVITY);
    m.max_acceleration         = RocketState_.thrust / mf;
    m.max_acceleration_g       = m.max_acceleration / GRAVITY;
    m.exceeds_g_limit          = m.max_acceleration_g > 35.0;

    return m;
}

// Print metrics
void print_engineering_report(const EngineeringMetrics& metrics){
    std::cout << "\n--- Engineering Analysis --------------------------------\n";
    std::cout << "Vehicle mass ratio                : " << metrics.MR_vehicle               << '\n';
    std::cout << "Propulsion-unit mass ratio        : " << metrics.MR_propulsion            << '\n';
    std::cout << "Propellant mass fraction (ζ)      : " << metrics.propellant_mass_fraction << '\n';
    std::cout << "Effective exhaust velocity (c)    : " << metrics.exhaust_velocity         << " m/s\n";
    std::cout << "Mass-flow rate (ṁ)                : " << metrics.mass_flow_rate           << " kg/s\n";
    std::cout << "Thrust                            : " << metrics.thrust                   << " N\n";
    std::cout << "Total impulse (I_t)               : " << metrics.total_impulse            << " N·s\n";
    std::cout << "Impulse-to-weight ratio           : " << metrics.impulse_to_weight_ratio  << " s\n";
    std::cout << "Max acceleration                  : " << metrics.max_acceleration         << " m/s²  ("
              << metrics.max_acceleration_g << " g)\n";
    if (metrics.exceeds_g_limit)
        std::cout << "WARNING: exceeds 35 gravity limit!\n";
    std::cout << "----------------------------------------------------------\n\n";
}
