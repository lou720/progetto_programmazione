#include "configLoader.hpp"

#include "doctest.h"

TEST_CASE("Function loadSimulation - valid_1") {
  nc::SimulationConfig sim_c =
      nc::loadSimulation("test/config_test/simulation_valid_1.config");
  CHECK(sim_c.dt == doctest::Approx(.1));
  CHECK(sim_c.steps == 1);
  CHECK(sim_c.G == 1);
  CHECK(sim_c.eps == doctest::Approx(.1));
  CHECK(sim_c.bodies.size() == 1);
  CHECK(sim_c.bodies[0].id() == 1);
  CHECK(sim_c.bodies[0].mass() == doctest::Approx(1));
  CHECK(sim_c.bodies[0].pos().y == doctest::Approx(1));
  CHECK(sim_c.bodies[0].pos().y == doctest::Approx(1));
  CHECK(sim_c.bodies[0].vel().x == doctest::Approx(1));
  CHECK(sim_c.bodies[0].vel().y == doctest::Approx(1));
}

TEST_CASE("Function loadSimulation - nonExistingFile") {
  CHECK_THROWS(nc::loadSimulation("nonExistingFile"));
}

TEST_CASE("Function loadSimulation - bad_1") {
  CHECK_THROWS_WITH(
      nc::loadSimulation("test/config_test/simulation_bad_1.config"),
      "Riga 12 key non riconosciuta: g");
}

TEST_CASE("Function loadSimulation - bad_2") {
  CHECK_THROWS_WITH(
      nc::loadSimulation("test/config_test/simulation_bad_2.config"),
      "Riga 9 key non inizializzata: G");
}

TEST_CASE("Function loadSimulation - bad_3") {
  CHECK_THROWS_WITH(nc::loadSimulation("test/config_test/simulation_bad_3.config"),
"Riga 10 valore in input non valido: body");
}