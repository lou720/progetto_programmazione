#include "vec2.hpp"

#include <cmath>

namespace nc {

Vec2& Vec2::operator+=(Vec2 const& v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) {
  x -= v.x;
  y -= v.y;
  return* this;
}

Vec2& Vec2::operator*=(double l) {
  x *= l;
  y *= l;
  return *this;
}

double Vec2::norm() const { return std::sqrt(x * x + y * y); }

double Vec2::norm2() const { return x * x + y * y; }

Vec2 operator+(Vec2 v1, Vec2 const& v2) {
    return v1 += v2;
}

Vec2 operator-(Vec2 v1, Vec2 const& v2) {
    return v1 -= v2;
}

bool operator==(Vec2 const& v1, Vec2 const& v2) {
    double eps{1e-9};
    Vec2 dv = v1 - v2;
    return dv.norm() < eps;
}

Vec2 operator*(Vec2 v, double l) {
    return v *= l;
}

Vec2 operator*(double l, Vec2 v) {
    return v *= l;
}

}  // namespace nc