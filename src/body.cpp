#include "body.hpp"

#include "vec2.hpp"

namespace nc {
Body::Body(int id, nc::Vec2 r, nc::Vec2 v, double mass)
    : id_{id}, r_{r}, v_{v}, mass_{mass} {}

nc::Vec2 const& Body::pos() const { return r_; }
nc::Vec2 const& Body::vel() const { return v_; }

}  // namespace nc
