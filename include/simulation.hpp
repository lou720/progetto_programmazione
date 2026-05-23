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
  Simulation(nc::SimulationConfig const& c);

  void run();

  void velocityVertel();
};
}  // namespace nc
#endif