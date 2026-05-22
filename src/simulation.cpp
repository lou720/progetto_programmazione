#include "simulation.hpp"

#include <iostream>

namespace nc {
Simulation::Simulation(nc::SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {}

void Simulation::run() { std::cout << "Comando run\n"; }
}  // namespace nc