#include "app.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace nc {
App::App(SimulationConfig const& s, RendererConfig const& r)
    : simulation_{s}, renderer_{r} {}

void App::run() {
  sf::RenderWindow window(sf::VideoMode(renderer_.width(), renderer_.height()),
                          renderer_.title());

  sf::View view;
  view.setCenter(sf::Vector2f{0.f, 0.f});
  view.setSize(sf::Vector2f{5.f, 5.f});

    // sf::View view{sf::FloatRect{-5.f, -5.f, 5.f, 5.f}};
  window.setView(view);

  while (window.isOpen()) {
    for (int i = 0; i < simulation_.steps(); ++i) {
      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
      }

      simulation_.step();

      window.clear(sf::Color::Black);

      renderer_.draw(window, simulation_.bodies());

      window.display();
    }
  }
}

}  // namespace nc