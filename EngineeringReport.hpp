#pragma once
#include "RocketStage.hpp"
#include "RocketState.hpp"
#include "EngineeringMetrics.hpp"


struct RocketState;

EngineeringMetrics print_engineering_report(const RocketStage& stage,
                              const RocketState& initial_state,
                              double payload_mass);