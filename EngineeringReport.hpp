#pragma once
#include "RocketStage.hpp"
#include "RocketState.hpp"
#include "EngineeringMetrics.hpp"


struct RocketState;

void print_engineering_report(const EngineeringMetrics& metrics);

EngineeringMetrics compute_engineering_metrics(const RocketStage& RocketStage_,
                                              const RocketState& RocketState_,
                                              double payload);