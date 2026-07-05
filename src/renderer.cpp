#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title},
      width_{r.width},
      height_{r.height},
      fps_{r.fps},
      physics_substeps_{r.physics_substeps_per_second},
      body_shape_{r.radius} {
  view_.setCenter({0., 0.});
  view_.setSize({7.5, 5.});

  body_shape_.setOrigin(r.radius, r.radius);
  body_shape_.setFillColor(sf::Color::White);
}

void Renderer::draw(sf::RenderWindow& w, std::vector<Body> const& v_bodies) {
  for (auto const& b : v_bodies) {
    body_shape_.setPosition(
        {static_cast<float>(b.pos().x), static_cast<float>(b.pos().y)});
    w.draw(body_shape_);
  }
}

std::string Renderer::title() const { return title_; }

unsigned int Renderer::width() const { return width_; }

unsigned int Renderer::height() const { return height_; }

unsigned int Renderer::fps() const { return fps_; }

double Renderer::physicsSubstepsPerSecond() const { return physics_substeps_; }

sf::View const& Renderer::view() const { return view_; }

}  // namespace nc