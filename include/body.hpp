#ifndef NC_BODY_HPP
#define NC_BODY_HPP

#include "include/vec2.hpp"

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
  Body(int id, nc::Vec2 r, nc::Vec2 v, double mass)
      : id_{id}, r_{r}, v_{v}, mass_{mass} {};

  nc::Vec2 const& Pos() const;
  nc::Vec2 const& Vel() const;
};

}  // namespace nc

#endif