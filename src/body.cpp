#include "body.hpp"

namespace nc {
Body::Body(int id, nc::Vec2 const& r, nc::Vec2 const& v, double mass)
    : id_{id}, r_{r}, v_{v}, mass_{mass} {}

nc::Vec2 const& Body::pos() const { return r_; }
nc::Vec2 const& Body::vel() const { return v_; }
nc::Vec2 const& Body::acc() const { return a_; }
double Body::mass() const { return mass_; }
int Body::id() const { return id_; }

void Body::pos(nc::Vec2 const& r_new) {
  r_.x = r_new.x;
  r_.y = r_new.y;
}

void Body::vel(nc::Vec2 const& v_new) {
    v_.x = v_new.x;    
    v_.y = v_new.y;    
}

}  // namespace nc
