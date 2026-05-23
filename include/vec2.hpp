#ifndef VEC2_HPP
#define VEC2_HPP

namespace nc {
struct Vec2 {
  double x;
  double y;

  Vec2& operator+=(Vec2 const&);
};

Vec2 operator+(Vec2 const&, Vec2 const&);

Vec2 operator-(Vec2 const&, Vec2 const&);

bool operator==(Vec2 const&, Vec2 const&);

Vec2 operator*(Vec2 const&, double);

Vec2 operator*(double, Vec2 const&);

}  // namespace nc
#endif