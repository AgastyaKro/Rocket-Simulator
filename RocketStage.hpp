#pragma once
#include "Constants.hpp"

struct RocketStage{
    double thrust;      // newtons
    double burn_time;   // seconds
    double fuel_mass;   // kg
    double dry_mass;    // kg
    double isp;         // seconds 

    RocketStage(double thrust_, double burn_time_, double fuel_mass_, double dry_mass_, double isp_)
            : thrust(thrust_), burn_time(burn_time_), fuel_mass(fuel_mass_), 
              dry_mass(dry_mass_), isp(isp_) {}

    double get_total_mass(){ 
        return dry_mass + fuel_mass;
    }

    double get_mass_flow_rate() const {
        return thrust / (isp * GRAVITY);
    }

    double get_thrust(double time){
        return (time <= burn_time ? thrust : 0); // no fuel after burn_time so no thrust
    }


};