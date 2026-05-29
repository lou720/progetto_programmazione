#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title},
      width_{r.width},
      height_{r.height},
      fps_{r.fps},
      physics_substeps_{r.physics_substeps},
      body_shape_{r.radius} {
  view_.setCenter(sf::Vector2f{0.f, 0.f});
  view_.setSize(sf::Vector2f{7.5f, 5.f});

  body_shape_.setOrigin(r.radius, r.radius);
  body_shape_.setFillColor(sf::Color::White);
}

void Renderer::draw(sf::RenderWindow& w, std::vector<Body> const& v_bodies) {
  for (auto const& b : v_bodies) {
    body_shape_.setPosition(sf::Vector2f{b.pos().x, b.pos().y});
    w.draw(body_shape_);
  }
}

std::string Renderer::title() const { return title_; }

unsigned int Renderer::width() const { return width_; }

unsigned int Renderer::height() const { return height_; }

unsigned int Renderer::fps() const { return fps_; }

int Renderer::physicsSubsteps() const { return physics_substeps_; }

sf::View const& Renderer::view() const { return view_; }

}  // namespace nc