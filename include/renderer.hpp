#ifndef NC_RENDERER_HPP
#define NC_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "body.hpp"
#include "rendererConfig.hpp"

namespace nc {
class Renderer {
 private:
  std::string title_{};
  unsigned int width_{};
  unsigned int height_{};
  unsigned int fps_{};
  double physics_substeps_{};
  sf::View view_;
  sf::CircleShape body_shape_;

 public:
  Renderer(RendererConfig const&);

  void draw(sf::RenderWindow&, std::vector<Body> const&);

  std::string title() const;

  unsigned int width() const;

  unsigned int height() const;

  unsigned int fps() const;

  double physicsSubstepsPerSecond() const;

  sf::View const& view() const;
};
}  // namespace nc

#endif