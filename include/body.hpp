#ifndef NC_BODY_HPP
#define NC_BODY_HPP

#include "vec2.hpp"

namespace nc {
class Body {
 private:
  int id_{};
  nc::Vec2 r_{};
  nc::Vec2 v_{};
  double mass_{};
  // double radius_{}; // Si può aggiungere il raggio
  // proporzionale alla massa

 public:
  Body(int id, nc::Vec2 r, nc::Vec2 v, double mass);
  nc::Vec2 const& pos() const;
  nc::Vec2 const& vel() const;
};

}  // namespace nc

#endif