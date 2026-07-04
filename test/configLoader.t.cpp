#include "configLoader.hpp"

#include "doctest.h"

TEST_CASE("Function loadSimulation - valid_1") {
  nc::SimulationConfig sim_c =
      nc::loadSimulation("test/config_test/simulation_valid_1.config");
  CHECK(sim_c.dt == doctest::Approx(.1));
  CHECK(sim_c.steps == 1);
  CHECK(sim_c.G == 1.);
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
      "Key non inizializzata: G");
}

TEST_CASE("Function loadSimulation - bad_3") {
  CHECK_THROWS_WITH(nc::loadSimulation("test/config_test/simulation_bad_3.config"),
"Riga 10 valore in input non valido: body");
}

TEST_CASE("Function loadSimulation - bad_4") {
  CHECK_THROWS_WITH(nc::loadSimulation("test/config_test/simulation_bad_4.config"),
  "Riga 4 valore in input non valido: steps");
}

TEST_CASE("Funcion loadRenderer - valid_1") {
  nc::RendererConfig ren_c = nc::loadRenderer("test/config_test/renderer_valid_1.config");
  CHECK(ren_c.title == "N-Body Simulator");
  CHECK(ren_c.width == 800);
  CHECK(ren_c.height == 600);
  CHECK(ren_c.fps == 60);
  CHECK(ren_c.physics_substeps == 15);
  CHECK(ren_c.velocity_substeps == doctest::Approx(15000));
  CHECK(ren_c.radius == doctest::Approx(0.1f));
}