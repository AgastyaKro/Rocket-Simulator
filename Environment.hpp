#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "Constants.hpp"

class Environment{
    private:
        double EnvTemperature;
        double EnvPressure;
        double EnvAltitude;
        double EnvDensity;
        
        // internal helper
        void computeEnvAtmosphere();

        
    public:
        // Constructors
        Environment();
        Environment(double EnvTemperature_, double EnvPressure_, double EnvAltitude_, double EnvDensity_);

        // Functions
        const double getEnvTemperature();
        const double getEnvPressure();
        const double getEnvAltitude();
        const double getEnvDensity();
        void updateEnvAltitude(int newAltitude);
};

#endif