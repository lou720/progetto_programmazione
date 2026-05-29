#ifndef NC_RENDERER_HPP
#define NC_RENDERER_HPP

#include <string>
#include <SFML/Graphics.hpp>

#include "rendererConfig.hpp"

namespace nc {
class Renderer {
 private:
 std::string title_{};
 unsigned int width_{};
 unsigned int height_{};
 unsigned int fps_{};

 public:
  Renderer(RendererConfig const&);

  void draw(sf::RenderWindow&);
};
}  // namespace nc

#endif