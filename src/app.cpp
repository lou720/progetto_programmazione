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
  int current_step{1};
  int physics_substep{10};

  while (window_.isOpen()) {
    sf::Event event;

    while (window_.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window_.close();
    }
    if (current_step == simulation_.steps()) {
      window_.close();
    }

    for (int i = 0; i < physics_substep; ++i) {
      simulation_.step();
    }

    window_.clear(sf::Color::Black);

    renderer_.draw(window_, simulation_.bodies());

    window_.display();

    ++current_step;
  }
}

}  // namespace nc