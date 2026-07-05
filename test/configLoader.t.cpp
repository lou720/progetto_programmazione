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
      "File test/config_test/simulation_bad_1.config   riga 12   key non "
      "riconosciuta: g");
}

TEST_CASE("Function loadSimulation - bad_2") {
  CHECK_THROWS_WITH(
      nc::loadSimulation("test/config_test/simulation_bad_2.config"),
      "File test/config_test/simulation_bad_2.config   key non inizializzata: "
      "G");
}

TEST_CASE("Function loadSimulation - bad_3") {
  CHECK_THROWS_WITH(
      nc::loadSimulation("test/config_test/simulation_bad_3.config"),
      "File test/config_test/simulation_bad_3.config   riga 10   valore in "
      "input non valido: body");
}

TEST_CASE("Function loadSimulation - bad_4") {
  CHECK_THROWS_WITH(
      nc::loadSimulation("test/config_test/simulation_bad_4.config"),
      "File test/config_test/simulation_bad_4.config   riga 4   valore in "
      "input non valido: steps");
}

TEST_CASE("Function loadSimulation - bad_5") {
  CHECK_THROWS(nc::loadSimulation("test/config_test/simulation_bad_5.config"));
}

TEST_CASE("Function loadRenderer - valid_1") {
  nc::RendererConfig ren_c =
      nc::loadRenderer("test/config_test/renderer_valid_1.config");
  CHECK(ren_c.width == 800);
  CHECK(ren_c.height == 600);
  CHECK(ren_c.fps == 60);
  CHECK(ren_c.radius == doctest::Approx(0.1f));
}

TEST_CASE("Function loadRenderer - bad_1") {
  CHECK_THROWS_WITH(nc::loadRenderer("test/config_test/renderer_bad_1.config"),
                    "File test/config_test/renderer_bad_1.config   riga 3   "
                    "valore in input non valido: width");
}

TEST_CASE("Function loadRenderer - bad_2") {
  CHECK_THROWS_WITH(nc::loadRenderer("test/config_test/renderer_bad_2.config"),
                    "File test/config_test/renderer_bad_2.config   riga 10   "
                    "key non riconosciuta: key");
}

TEST_CASE("Function loadRenderer - bad_3") {
  CHECK_THROWS_WITH(nc::loadRenderer("test/config_test/renderer_bad_3.config"),
                    "File test/config_test/renderer_bad_3.config   key non "
                    "inizializzata: fps");
}