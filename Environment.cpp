#include "Environment.hpp"

Environment::Environment() : EnvTemperature(DEFAULT_ENV_TEMP), EnvPressure(DEFAULT_ENV_PRESSURE), 
                            EnvAltitude(DEFAULT_ENV_ALTITUDE), EnvDensity(DEFAULT_ENV_DENSITY) {};
Environment::Environment(double EnvTemperature_, double EnvPressure_, double EnvAltitude_, double EnvDensity_) : 
                            EnvTemperature(EnvTemperature_), EnvPressure(EnvPressure_), 
                            EnvAltitude(EnvAltitude_), EnvDensity(EnvDensity_) {};


const double Environment::getEnvAltitude() {
    return EnvAltitude;
}
const double Environment::getEnvDensity(){
    return EnvDensity;
}
const double Environment::getEnvPressure(){
    return EnvPressure;
}
const double Environment::getEnvTemperature(){
    return EnvTemperature;
}

void Environment::computeEnvAtmosphere(){

}