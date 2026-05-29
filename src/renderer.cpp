#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title}, width_{r.width}, height_{r.height}, fps_{r.fps} {
  view_.setCenter(sf::Vector2f{0.f, 0.f});
  view_.setSize(sf::Vector2f{7.5f, 5.f});
}

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

sf::View const& Renderer::view() const { return view_; }

}  // namespace nc