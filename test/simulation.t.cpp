#include "simulation.hpp"

#include "doctest.h"

TEST_CASE("Function kineticEnergy") {
  std::vector<nc::Body> b1 = {{1, {2.0, -1.0}, {3.0, 4.0}, 5.0}};
  std::vector<nc::Body> b2 = {{1, {0.0, 0.0}, {0.0, 0.0}, 2.0},
                              {2, {2.0, 0.0}, {0.0, 0.0}, 3.0}};
  std::vector<nc::Body> b3 = {{1, {0.0, 0.0}, {1.0, 2.0}, 2.0},
                              {2, {3.0, 0.0}, {-1.0, 0.0}, 1.0},
                              {3, {0.0, 4.0}, {0.0, -2.0}, 3.0}};

  CHECK(nc::kineticEnergy(b1) == doctest::Approx(62.5));
  CHECK(nc::kineticEnergy(b2) == doctest::Approx(0));
  CHECK(nc::kineticEnergy(b3) == doctest::Approx(11.5));
}

TEST_CASE("Function potentialEnergy") {
  std::vector<nc::Body> b1 = {{1, {2.0, -1.0}, {3.0, 4.0}, 5.0}};
  std::vector<nc::Body> b2 = {{1, {0.0, 0.0}, {0.0, 0.0}, 2.0},
                              {2, {2.0, 0.0}, {0.0, 0.0}, 3.0}};
  std::vector<nc::Body> b3 = {{1, {0.0, 0.0}, {1.0, 2.0}, 2.0},
                              {2, {3.0, 0.0}, {-1.0, 0.0}, 1.0},
                              {3, {0.0, 4.0}, {0.0, -2.0}, 3.0}};
  double G{1};
  double eps{0};

  CHECK(nc::potentialEnergy(b1, G, eps) == doctest::Approx(0));
  CHECK(nc::potentialEnergy(b2, G, eps) == doctest::Approx(-3));
  CHECK(nc::potentialEnergy(b3, G, eps) == doctest::Approx(-2.76666));
}

TEST_CASE("Function totalEnergy") {
  std::vector<nc::Body> b1 = {{1, {2.0, -1.0}, {3.0, 4.0}, 5.0}};
  std::vector<nc::Body> b2 = {{1, {0.0, 0.0}, {0.0, 0.0}, 2.0},
                              {2, {2.0, 0.0}, {0.0, 0.0}, 3.0}};
  std::vector<nc::Body> b3 = {{1, {0.0, 0.0}, {1.0, 2.0}, 2.0},
                              {2, {3.0, 0.0}, {-1.0, 0.0}, 1.0},
                              {3, {0.0, 4.0}, {0.0, -2.0}, 3.0}};
  double G{1};
  double eps{0};

  CHECK(nc::totalEnergy(b1, G, eps) == doctest::Approx(62.5));
  CHECK(nc::totalEnergy(b2, G, eps) == doctest::Approx(-3));
  CHECK(nc::totalEnergy(b3, G, eps) == doctest::Approx(8.73333));
}

TEST_CASE("Function computeAccelerations") {
  std::vector<nc::Body> b1 = {{1, {2.0, -1.0}, {3.0, 4.0}, 5.0}};
  std::vector<nc::Body> b2 = {{1, {0.0, 0.0}, {0.0, 0.0}, 2.0},
                              {2, {2.0, 0.0}, {0.0, 0.0}, 3.0}};
  std::vector<nc::Body> b3 = {{1, {0.0, 0.0}, {1.0, 2.0}, 2.0},
                              {2, {3.0, 0.0}, {-1.0, 0.0}, 1.0},
                              {3, {0.0, 4.0}, {0.0, -2.0}, 3.0}};
  double G{1};
  double eps{0};

  CHECK(nc::computeAccelerations(b1, b1[0], G, eps).x == doctest::Approx(0));
  CHECK(nc::computeAccelerations(b1, b1[0], G, eps).y == doctest::Approx(0));


  CHECK(nc::computeAccelerations(b2, b2[0], G, eps).x == doctest::Approx(.75));
  CHECK(nc::computeAccelerations(b2, b2[0], G, eps).y == doctest::Approx(0));

  CHECK(nc::computeAccelerations(b2, b2[1], G, eps).x == doctest::Approx(-.5));
  CHECK(nc::computeAccelerations(b2, b2[1], G, eps).y == doctest::Approx(0));


   CHECK(nc::computeAccelerations(b3, b3[0], G, eps).x == doctest::Approx(.111111));
  CHECK(nc::computeAccelerations(b3, b3[0], G, eps).y == doctest::Approx(.1875));

  CHECK(nc::computeAccelerations(b3, b3[1], G, eps).x == doctest::Approx(-.2942222222));
  CHECK(nc::computeAccelerations(b3, b3[1], G, eps).y == doctest::Approx(.096));

  CHECK(nc::computeAccelerations(b3, b3[2], G, eps).x == doctest::Approx(.024));
  CHECK(nc::computeAccelerations(b3, b3[2], G, eps).y == doctest::Approx(-.157));
}