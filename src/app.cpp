#include "app.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace nc {
App::App(SimulationConfig const& s, RendererConfig const& r)
    : simulation_{s}, renderer_{r} {}

void App::run() {
  sf::RenderWindow window(sf::VideoMode(renderer_.width(), renderer_.height()),
                          renderer_.title());

  window.setFramerateLimit(renderer_.fps());

  sf::View view;
  view.setCenter(sf::Vector2f{0.f, 0.f});
  view.setSize(sf::Vector2f{7.5f, 5.f});

  window.setView(view);

  int current_step{1};
  int physics_substep{15};

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    if (current_step == simulation_.steps()) {
      window.close();
    }

    for (int i = 0; i < physics_substep; ++i) {
      simulation_.step();
    }

    window.clear(sf::Color::Black);

    renderer_.draw(window, simulation_.bodies());

    window.display();

    ++current_step;
  }
}

}  // namespace nc