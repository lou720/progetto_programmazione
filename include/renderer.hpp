#ifndef NC_RENDERER_HPP
#define NC_RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "rendererConfig.hpp"
#include "body.hpp"

namespace nc {
class Renderer {
 private:
  std::string title_{};
  unsigned int width_{};
  unsigned int height_{};
  unsigned int fps_{};
  int phisics_substeps_{};
  sf::View view_;

 public:
  Renderer(RendererConfig const&);

  void draw(sf::RenderWindow&, std::vector<Body> const&);

  std::string title() const;

  unsigned int width() const;

  unsigned int height() const;

  unsigned int fps() const;

  sf::View const& view() const;
};
}  // namespace nc

#endif