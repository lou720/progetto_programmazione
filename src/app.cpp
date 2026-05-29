#include "app.hpp"

namespace nc {

App::App(SimulationConfig const& s, RendererConfig const& r)
    : simulation_{s},
      renderer_{r},
      window_{sf::VideoMode(r.width, r.height), r.title} {
  window_.setFramerateLimit(renderer_.fps());
  window_.setView(renderer_.view());
}

void App::run() {
  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window_.close();
    }
    if (simulation_.finished()) {
      window_.close();
    }

    for (int i = 0; i < renderer_.physicsSubsteps(); ++i) {
      simulation_.step();
    }

    window_.clear(sf::Color::Black);

    renderer_.draw(window_, simulation_.bodies());

    window_.display();
  }
}

}  // namespace nc