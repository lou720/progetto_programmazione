#include "app.hpp"

namespace nc {

App::App(SimulationConfig const& s, RendererConfig const& r, double time_scale)
    : simulation_{s},
      renderer_{r},
      time_scale_{time_scale},
      window_{sf::VideoMode(r.width, r.height), r.title} {
  window_.setFramerateLimit(renderer_.fps());
  window_.setView(renderer_.view());
}

void App::run() {
  sf::Clock clock;
  double accumulator{};
  while (window_.isOpen()) {
    double elapsed = clock.restart().asSeconds();
    accumulator += elapsed * time_scale_;

    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window_.close();
    }
    if (simulation_.finished()) {
      window_.close();
    }

    while (accumulator >= simulation_.dt()) {
      simulation_.step();
      accumulator -= simulation_.dt();
    }

    window_.clear(sf::Color::Black);

    renderer_.draw(window_, simulation_.bodies());

    window_.display();
  }
}

}  // namespace nc