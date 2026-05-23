#ifndef NC_BODY_HPP
#define NC_BODY_HPP

#include "vec2.hpp"

namespace nc {

class Body {
 private:
  int id_{};

  Vec2 r_{};
  Vec2 v_{};
  Vec2 a_{};

  double mass_{};

  // double radius_{};
  // Si può aggiungere il raggio
  // proporzionale alla massa

 public:
  Body(int id, Vec2 const& r, Vec2 const& v, double mass);

  // getter
  Vec2 const& pos() const;
  Vec2 const& vel() const;
  Vec2 const& acc() const;

  double mass() const;
  int id() const;

  // setter
  void pos(Vec2 const&);
  void vel(Vec2 const&);
  void acc(Vec2 const&);
};

}  // namespace nc

#endif