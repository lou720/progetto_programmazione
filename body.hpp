#ifndef NC_BODY_HPP
#define NC_BODY_HPP

#include <SFML/System/Vector2.hpp>

namespace nc {
class Body {
 private:
  int tag_{0};
  sf::Vector2f r_{0.f, 0.f};
  sf::Vector2f v_{0.f, 0.f};
  float mass_{0.f};
  float radius_{0.f};

 public:
  Body();
  Body(int tag, sf::Vector2f r, sf::Vector2f v, float mass, float radius);

  sf::Vector2f const& Pos() const;
  sf::Vector2f const& Vel() const;
};

}  // namespace nc

#endif