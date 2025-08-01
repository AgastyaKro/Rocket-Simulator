#include "RocketState.hpp"
#include <sstream>
#include "Constants.hpp"

RocketState compute_state(double time, double position, double velocity,
                          double fuel_mass, const RocketStage& stage) {
    RocketState state;
    state.time = time;
    state.position = position;
    state.velocity = velocity;
    state.fuel_mass = fuel_mass;
    state.mass = stage.dry_mass + fuel_mass;

    state.thrust = (fuel_mass > 0 && time <= stage.burn_time) ? stage.thrust : 0.0;
    state.mass_flow_rate = (state.thrust > 0.0) ? stage.get_mass_flow_rate() : 0.0;

    state.weight = state.mass * GRAVITY;
    state.net_force = state.thrust - state.weight;
    state.acceleration = state.net_force / state.mass;
    state.acceleration_g = state.acceleration / GRAVITY;
    state.drag = 0.0;

    return state;
}

std::string RocketState::to_csv_row() const {
    std::ostringstream ss;
    ss << time << ","
       << position << ","
       << velocity << ","
       << acceleration << ","
       << acceleration_g << ","
       << mass << ","
       << fuel_mass << ","
       << thrust << ","
       << mass_flow_rate;
    return ss.str();
}
