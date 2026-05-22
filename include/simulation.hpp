#ifndef NC_SIMULATION_HPP
#define NC_SIMULATION_HPP

#include <vector>
#include "body.hpp"
#include "simulationConfig.hpp"

namespace nc {
class Simulation {
  private:
  int steps_{};
  double dt_{};
  double G_{};
  double eps_{};
  std::vector<nc::Body> bodies_{};

 public:
 Simulation(nc::SimulationConfig c) : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps} {
  bodies_.reserve(c.bodies.size());
  for (auto const& i : c.bodies) {
    bodies_.emplace_back(i);
  }
 }
  void run();

};
}  // namespace nc
#endif