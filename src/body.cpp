#include "body.hpp"

namespace nc {
Body::Body(int id, Vec2 const& r, Vec2 const& v, double mass)
    : id_{id}, r_{r}, v_{v}, mass_{mass} {}

Vec2 const& Body::pos() const { return r_; }

Vec2 const& Body::vel() const { return v_; }

Vec2 const& Body::acc() const { return a_; }

double Body::mass() const { return mass_; }

int Body::id() const { return id_; }

void Body::setPos(nc::Vec2 const& r_new) { r_ = r_new; }

void Body::setVel(nc::Vec2 const& v_new) { v_ = v_new; }

void Body::setAcc(nc::Vec2 const& a_new) { a_ = a_new; }

}  // namespace nc
