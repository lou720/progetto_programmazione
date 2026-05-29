#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title}, width_{r.width}, height_{r.height}, fps_{r.fps} {}

void Renderer::draw(sf::RenderWindow& w, std::vector<Body> const& v_bodies) {
  sf::CircleShape shape{0.1f};
  shape.setOrigin(0.1f, 0.1f);
  shape.setFillColor(sf::Color::White);

  for (auto const& b : v_bodies) {
    shape.setPosition(sf::Vector2f{b.pos().x, b.pos().y});
    w.draw(shape);
  }
} 

std::string Renderer::title() const { return title_; }

unsigned int Renderer::width() const { return width_; }

unsigned int Renderer::height() const { return height_; }

unsigned int Renderer::fps() const { return fps_; }

}  // namespace nc