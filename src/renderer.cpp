#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title}, width_{r.width}, height_{r.height}, fps_{r.fps} {}

void Renderer::draw(sf::RenderWindow& w, std::vector<Body> const& v_bodies) {
    float scale{100.f};
  for (auto const& b : v_bodies) {
    sf::CircleShape shape{8.f};
    sf::Vector2f body_pos{
        b.pos().x * scale, 
        b.pos().y * scale
    };
    shape.setPosition(body_pos);
    w.draw(shape);
  }
}

std::string Renderer::title() const { return title_; }

unsigned int Renderer::width() const { return width_; }

unsigned int Renderer::height() const { return height_; }

unsigned int Renderer::fps() const { return fps_; }

}  // namespace nc