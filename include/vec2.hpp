#ifndef VEC2_HPP
#define VEC2_HPP

namespace nc {
struct Vec2 {
  double x;
  double y;

  Vec2& operator+=(Vec2 const& v);
};

Vec2 operator+(Vec2 const& v1, Vec2 const& v2);

bool operator==(Vec2 const& v1, Vec2 const& v2);


}  // namespace nc
#endif