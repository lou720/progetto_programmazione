#include "simulation.hpp"

#include <iostream>

#include "vec2.hpp"

namespace nc {
Simulation::Simulation(nc::SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {}

void Simulation::run() { std::cout << "Comando run\n"; }

void Simulation::velocityVertel() {
    for (auto const& body : bodies_) {
        nc::Vec2 r_new = body.pos() + body.vel()*dt_ + .5*body.acc()*dt_*dt_; 
    }
}
}  // namespace nc