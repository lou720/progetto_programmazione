#include "app.hpp"

#include <SFML/Graphics.hpp>

namespace nc {
App::App(SimulationConfig const& s, RendererConfig const& r)
    : simulation_{s}, renderer_{r} {}

void App::run() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    for (int i = 0; i < simulation_.steps(); ++i) {
      simulation_.step();
      renderer_.draw(window);
    }
  }
}

}  // namespace nc