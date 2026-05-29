#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title}, width_{r.width}, height_{r.height}, fps_{r.fps} {}

void Renderer::draw(sf::RenderWindow& w) {
    w.clear(sf::Color::Black);
    w.draw(sf::CircleShape(50.f));
    w.display();
}

}  // namespace nc