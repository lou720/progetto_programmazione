#include "vec2.hpp"

#include "doctest.h"

TEST_CASE("Vec2 operator+=") {
  nc::Vec2 v1{1., 1.};
  nc::Vec2 v2{1., 1.};
  nc::Vec2 v3{-1., 0};
  v1 += v2;
  v2 += v3;
  CHECK(v1.x == doctest::Approx(2));
  CHECK(v1.y == doctest::Approx(2.));
  CHECK(v2.x == doctest::Approx(0));
  CHECK(v2.y == doctest::Approx(1));
}

TEST_CASE("Vec2 operator-=") {
  nc::Vec2 v1{1., 1.};
  nc::Vec2 v2{1., 1.};
  nc::Vec2 v3{-1., 0};
  v1 -= v2;
  v3 -= v1;
  CHECK(v1.x == doctest::Approx(0));
  CHECK(v1.y == doctest::Approx(0));
  CHECK(v3.x == doctest::Approx(-1));
  CHECK(v3.y == doctest::Approx(0));
  v1 -= v3;
  CHECK(v1.x == doctest::Approx(1));
  CHECK(v1.y == doctest::Approx(0));
}

TEST_CASE("Vec2 operator*=") {
  nc::Vec2 v1{1, 2};
  nc::Vec2 v2{.5, 2};
  nc::Vec2 v3{-1, -.8};
  v1 *= 2;
  v2 *= -.5;
  v3 *= -1;
  CHECK(v1.x == doctest::Approx(2));
  CHECK(v1.y == doctest::Approx(4));
  CHECK(v2.x == doctest::Approx(-.25));
  CHECK(v2.y == doctest::Approx(-1));
  CHECK(v3.x == doctest::Approx(1));
  CHECK(v3.y == doctest::Approx(.8));
  v1 *= 0;
  CHECK(v1.x == doctest::Approx(0));
  CHECK(v1.y == doctest::Approx(0));
}

TEST_CASE("Vec2 norm2()") {
  nc::Vec2 v1{1, 2};
  nc::Vec2 v2{};
  nc::Vec2 v3{-1, -.8};
  CHECK(v1.norm2() == doctest::Approx(5));
  CHECK(v2.norm2() == doctest::Approx(0));
  CHECK(v3.norm2() == doctest::Approx(1.64));
}

TEST_CASE("Vec2 operator+") {
  nc::Vec2 v1{1., 1.};
  nc::Vec2 v2{1., 1.};
  nc::Vec2 v3{-1., 0};
  auto s1 = v1 + v2;
  auto s2 = s1 + v3;
  CHECK(s1.x == doctest::Approx(2));
  CHECK(s1.y == doctest::Approx(2));
  CHECK(s2.x == doctest::Approx(1));
  CHECK(s2.y == doctest::Approx(2));
}

TEST_CASE("Vec2 operator-") {
  nc::Vec2 v1{1., 1.};
  nc::Vec2 v2{1., 1.};
  nc::Vec2 v3{-1., 0};
  auto d1 = v3 - v1;
  auto d2 = v2 - d1;
  CHECK(d1.x == doctest::Approx(-2));
  CHECK(d1.y == doctest::Approx(-1));
  CHECK(d2.x == doctest::Approx(3));
  CHECK(d2.y == doctest::Approx(2));
}

TEST_CASE("Vec2 operator==") {
  nc::Vec2 v1{1., 1.};
  nc::Vec2 v2{1., .999'999'99};
  nc::Vec2 v3{.999'999'99, 1};
  nc::Vec2 v4{1., 1};
  nc::Vec2 v5{1., .999'999'999};  // double troppo lungo
  bool e1 = (v1 == v2);
  bool e2 = (v1 == v3);
  bool e3 = (v1 == v4);
  bool e4 = (v1 == v5);  // true
  CHECK(e1 == false);
  CHECK(e2 == false);
  CHECK(e3 == true);
  CHECK(e4 == true);  // passed
}

TEST_CASE("Vec2 operator*") {
  nc::Vec2 v1{2, 3};
  double k{2};
  auto p1 = v1 * k;
  auto p2 = k * v1;
  CHECK(p1.x == doctest::Approx(4));
  CHECK(p1.y == doctest::Approx(6));
  CHECK(p2.x == doctest::Approx(4));
  CHECK(p2.y == doctest::Approx(6));
  CHECK(p1 == p2);

  p1 = v1 * 0;
  p2 = 0 * v1;
  CHECK(p1.x == doctest::Approx(0));
  CHECK(p1.y == doctest::Approx(0));
  CHECK(p2.x == doctest::Approx(0));
  CHECK(p2.y == doctest::Approx(0));
  CHECK(p1 == p2);

  nc::Vec2 v2{0, 0};
  p1 = v2 * 2;
  p2 = 2 * v2;
  CHECK(p1.x == doctest::Approx(0));
  CHECK(p1.y == doctest::Approx(0));
  CHECK(p2.x == doctest::Approx(0));
  CHECK(p2.y == doctest::Approx(0));
  CHECK(p1 == p2);
}