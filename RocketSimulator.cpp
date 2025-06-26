#include "RocketSimulator.hpp"

const double GRAVITY = 9.81;

RocketSimulator::RocketSimulator(RocketStage stage, double dt)  : stage(stage), dt(dt), time(0.0), position(0.0), velocity(0.0){}

void RocketSimulator::log_state(std::ostream& out, double mass, double acceleration){
    out << time << "," << position << "," << velocity << "," << acceleration << "," << mass << "\n";
}

void RocketSimulator::run_simulation(std::ostream& out){
    out << "time,position,velocity,acceleration,mass\n";

    while (position >= 0) {
        double mass = stage.get_mass(time);
        double thrust = stage.get_thrust(time);
        double weight = mass * GRAVITY;
        double net_force = thrust - weight;
        double acceleration = net_force / mass;

        velocity += acceleration * dt;
        position += velocity * dt;

        log_state(out, mass, acceleration);
        time += dt;

        if (velocity <= 0 && time > stage.burn_time) break;

    }
}

