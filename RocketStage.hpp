#pragma once
#include <iostream>
#include <cmath>
#include "Constants.hpp"

struct RocketStage{
    double thrust;      // newtons
    double burn_time;   // seconds
    double fuel_mass;   // kg
    double dry_mass;    // kg
    double isp;         // seconds 
    double nozzle_exit_area{.5}; // m^2, A2
    double nozzle_throat_area{0.025}; // m^2, At
    double nozzle_gas_pressure; // Pa
    const double starting_chamber_pressure{7e6};
    const double gas_specific_heat_ratio{1.22};
    double mach_at_nozzle_exit{3.0};


    RocketStage(double thrust_, double burn_time_, double fuel_mass_, double dry_mass_, double isp_, double exit_nozzle_area_)
            : thrust(thrust_), burn_time(burn_time_), fuel_mass(fuel_mass_), 
              dry_mass(dry_mass_), isp(isp_), nozzle_exit_area(exit_nozzle_area_) {}

    double get_total_mass(){ 
        return dry_mass + fuel_mass;
    }

    double get_mass_flow_rate() const {
        return thrust / (isp * GRAVITY);
    }

    double get_thrust(double time){
        return (time <= burn_time ? thrust : 0); // no fuel after burn_time so no thrust
    }

    void computeNozzleGasPressure(){
        double gamma = gas_specific_heat_ratio;
        double M2 = mach_at_nozzle_exit;

        double base = 1.0 + ((gamma - 1.0) / 2.0) * M2 * M2;
        double exponent = -gamma / (gamma - 1.0);;

        double pressure_ratio = std::pow(base, exponent);

        nozzle_gas_pressure = starting_chamber_pressure * pressure_ratio;

    } 


};