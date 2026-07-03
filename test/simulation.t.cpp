#include "simulation.hpp"
#include "simulationConfig.hpp"

#include "doctest.h"

TEST_CASE("Comportamento normale di Simulation") {
    nc::SimulationConfig sim_c{};
    sim_c.steps = 10000;
    sim_c.dt = .001;
    sim_c.eps = 1e-12;
    // nc::Simulation sim{};
}