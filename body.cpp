#include "body.hpp"

namespace nc {
Body::Body() = default;
Body::Body(int tag, sf::Vector2f r, sf::Vector2f v, float mass, float radius)
    : tag_{tag}, r_{r}, v_{v}, mass_{mass}, radius_{radius} {};
sf::Vector2f const& Body::Pos() const { return r_; }
sf::Vector2f const& Body::Vel() const { return v_; }
}  // namespace nc
