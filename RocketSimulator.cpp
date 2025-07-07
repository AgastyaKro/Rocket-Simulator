#include "RocketSimulator.hpp"

constexpr double GRAVITY = 9.81;

RocketSimulator::RocketSimulator(RocketStage stage, double dt)  : stage(stage), dt(dt), time(0.0), position(0.0), velocity(0.0){}

void RocketSimulator::log_state(std::ostream& out, double mass, double acceleration){
    out << time << "," << position << "," << velocity << "," << acceleration << "," << mass << "\n";
}

void RocketSimulator::run_simulation(std::ostream& out){
    out << "time,position,velocity,acceleration,mass\n";

    double fuel_mass = stage.fuel_mass;           // track fuel separately
    double dry_mass = stage.dry_mass;
    double mass;

    while (position >= 0) {
        // Compute mass and thrust
        mass = dry_mass + fuel_mass;
        double thrust = (fuel_mass > 0 && time <= stage.burn_time) ? stage.thrust : 0.0;

        // Burn fuel if burning
        if (thrust > 0.0) {
            double mass_flow_rate = stage.get_mass_flow_rate();
            fuel_mass -= mass_flow_rate * dt;
            if (fuel_mass < 0.0) fuel_mass = 0.0;
        }

        // Forces
        double weight = mass * GRAVITY;
        double net_force = thrust - weight;
        double acceleration = net_force / mass;

        // Integration
        velocity += acceleration * dt;
        position += velocity * dt;

        // Log
        log_state(out, mass, acceleration);
        time += dt;

        // Stop at peak after burn
        if (velocity <= 0 && time > stage.burn_time) break;
    }
}
