#pragma once

struct EngineeringMetrics {
    double MR_vehicle;
    double MR_propulsion;
    double propellant_mass_fraction;
    double exhaust_velocity;
    double mass_flow_rate;
    double thrust;
    double total_impulse;
    double impulse_to_weight_ratio;
    double max_acceleration;
    double max_acceleration_g;

    bool exceeds_g_limit = false;
};
