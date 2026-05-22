#ifndef NC_BODY_HPP
#define NC_BODY_HPP

#include "include/vec2.hpp"

namespace nc {
class Body {
 private:
  int id_{};
  nc::Vec2 r_{};
  nc::Vec2 v_{};
  float mass_{};
  // float radius_{}; // Si può aggiungere il raggio
                      // proporzionale alla massa

 public:
  Body();

  nc::Vec2 const& Pos() const;
  nc::Vec2 const& Vel() const;
};

}  // namespace nc

#endif