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
  std::vector<Body> bodies_{};

 public:
  Simulation(SimulationConfig const&);

  void run();

  void velocityVerlet();

  double kineticEnergy() const;

  double potencialEnergy() const;

  double totalEnergy() const;
};
}  // namespace nc
#endif