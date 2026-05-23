#include "simulation.hpp"

#include <iostream>

#include "vec2.hpp"

namespace nc {

Simulation::Simulation(SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {}

void Simulation::run() { std::cout << "Comando run\n"; }

void Simulation::velocityVertel() {
  for (auto& b : bodies_) {
    Vec2 r_new = b.pos() + b.vel() * dt_ + 0.5 * b.acc() * dt_ * dt_;

    b.pos(r_new);

    Vec2 a_new{};

    Vec2 v_new = b.vel() + 0.5 * (b.acc() + a_new) * dt_;

    b.acc(a_new);
    b.vel(v_new);
  }
}

}  // namespace nc