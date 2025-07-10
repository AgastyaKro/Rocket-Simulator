#pragma once
#include "RocketStage.hpp"
#include "RocketState.hpp"


struct RocketState;

void print_engineering_report(const RocketStage& stage,
                              const RocketState& initial_state,
                              double payload_mass);