#ifndef VEC2_HPP
#define VEC2_HPP

namespace nc {
struct Vec2 {
  double x{};
  double y{};

  Vec2& operator+=(Vec2 const&);

  Vec2& operator-=(Vec2 const&);

  Vec2& operator*=(double);

  double norm2() const;
  // return x*x + y*y;
};

Vec2 operator+(Vec2, Vec2 const&);
// return v1 += v2;

Vec2 operator-(Vec2, Vec2 const&);

bool operator==(Vec2, Vec2 const&);
// attenzione ai valori double

Vec2 operator*(Vec2, double);

Vec2 operator*(double, Vec2);

}  // namespace nc
#endif