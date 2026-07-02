#ifndef NC_SIMULATION_HPP
#define NC_SIMULATION_HPP

#include <vector>

#include "body.hpp"
#include "simulationConfig.hpp"

namespace nc {
class Simulation {
 private:
  int steps_{};
  int current_step_{};
  double dt_{};
  double G_{};
  double eps_{};
  std::vector<Body> bodies_{};

 public:
  Simulation(SimulationConfig const&);

  void step();

  void velocityVerlet();

  double kineticEnergy() const;

  double potentialEnergy() const;

  double totalEnergy() const;

  Vec2 computeAccelerations(Body const&) const;

  std::vector<Body> const& bodies() const;

  bool finished() const;
};
}  // namespace nc
#endif