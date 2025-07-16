#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "Constants.hpp"

class Environment{
    struct startingEnv{
        double Temperature;
        double Pressure;
        double Altitude;
        double Density;
    };

    private:
        double EnvTemperature;
        double EnvPressure;
        double EnvAltitude;
        double EnvDensity;
        
        startingEnv initialConditions;

        
        // internal helper
        void computeEnvAtmosphere();

        
    public:
        // Constructors
        Environment();
        Environment(double startingEnvTemperature, double EnvPressure_, double EnvAltitude_, double EnvDensity_);


        // Functions
        const double getEnvTemperature();
        const double getEnvPressure();
        const double getEnvAltitude();
        const double getEnvDensity();
        void updateEnvAltitude(double newAltitude);
};

#endif