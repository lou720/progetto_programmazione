#include "body.hpp"

#include "doctest.h"

TEST_CASE("Getter") {
  nc::Body b{1, nc::Vec2{1, 1}, nc::Vec2{1, 1}, 1};
  CHECK(b.pos().x == doctest::Approx(1));
  CHECK(b.pos().y == doctest::Approx(1));
  CHECK(b.vel().x == doctest::Approx(1));
  CHECK(b.vel().y == doctest::Approx(1));
  CHECK(b.acc().x == doctest::Approx(0));
  CHECK(b.acc().y == doctest::Approx(0));
  CHECK(b.mass() == doctest::Approx(1));
}

TEST_CASE("Setter") {
  nc::Body b{1, nc::Vec2{1, 1}, nc::Vec2{1, 1}, 1};
  b.setPos({2, 3});
  b.setVel({4, 5});
  b.setAcc({-1, 4});
  CHECK(b.pos().x == doctest::Approx(2));
  CHECK(b.pos().y == doctest::Approx(3));
  CHECK(b.vel().x == doctest::Approx(4));
  CHECK(b.vel().y == doctest::Approx(5));
  CHECK(b.acc().x == doctest::Approx(-1));
  CHECK(b.acc().y == doctest::Approx(4));
}