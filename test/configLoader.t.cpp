#include "doctest.h"
#include "configLoader.hpp"

TEST_CASE("Function loadSimulation - valid_1") {
    nc::SimulationConfig sim_c = nc::loadSimulation("test/config_test/simulation_valid_1.config");
    CHECK(sim_c.dt == doctest::Approx(.1));
    CHECK(sim_c.steps == 2);
    CHECK(sim_c.G == 2);
    CHECK(sim_c.eps == doctest::Approx(.1));
    CHECK(sim_c.bodies.size() == 1);
    CHECK(sim_c.bodies[0].id() == 1);
    CHECK(sim_c.bodies[0].mass() == doctest::Approx(1));
    CHECK(sim_c.bodies[0].vel().x == doctest::Approx(1));
}