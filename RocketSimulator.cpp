#include "RocketSimulator.hpp"
#include "RocketState.hpp"
#include "RocketStage.hpp"
#include "EngineeringReport.hpp"
#include "Constants.hpp"



RocketSimulator::RocketSimulator(RocketStage stage, double dt)  : stage(stage), dt(dt), time(0.0), position(0.0), velocity(0.0){}


void RocketSimulator::log_state(std::ostream& out, const RocketState& s) {
    out << s.to_csv_row() << "\n";
}

RocketState RocketSimulator::compute_step(double& fuel_mass) {
    if (fuel_mass > 0.0 && time <= stage.burn_time) {
        double mdot = stage.get_mass_flow_rate();
        fuel_mass -= mdot * dt;
        if (fuel_mass < 0.0) fuel_mass = 0.0;
    }

    return compute_state(time, position, velocity, fuel_mass, stage);
}

void RocketSimulator::apply_kinematics(double acceleration) {
    velocity += acceleration * dt;
    position += velocity * dt;
}


void RocketSimulator::run_simulation(std::ostream& out) {
    // One-time engineering report
    RocketState initial_state = compute_state(0.0, 0.0, 0.0, stage.fuel_mass, stage);
    EngineeringMetrics metrics = compute_engineering_metrics(stage, initial_state, /*payload=*/110.0);
    print_engineering_report(metrics);

    // Header for CSV
    out << "time,position,velocity,acceleration,acceleration_g,mass,fuel_mass,thrust,mass_flow_rate\n";

    // Run trajectory
    double fuel_mass = stage.fuel_mass;
    while (position >= 0) {
        RocketState state = compute_step(fuel_mass);
        apply_kinematics(state.acceleration);
        log_state(out, state);
        time += dt;

        if (velocity <= 0 && time > stage.burn_time)
            break;
    }
}
