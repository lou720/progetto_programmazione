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
  double E_{};
  std::vector<Body> bodies_{};

 public:
  Simulation(SimulationConfig const&);

  void step();

  void velocityVerlet();

  std::vector<Body> const& bodies() const;

  double dt() const;

  bool finished() const;
};

double kineticEnergy(std::vector<Body> const&);

double potentialEnergy(std::vector<Body> const&, double G, double eps);

double totalEnergy(std::vector<Body> const&, double G, double eps);

Vec2 computeAccelerations(std::vector<Body> const&, Body const&, double G,
                          double eps);

}  // namespace nc
#endif