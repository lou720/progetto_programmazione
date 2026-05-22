#ifndef NC_SIMULATION_CONFIG_HPP
#define NC_SIMULATION_CONFIG_HPP

#include <vector>

#include "body.hpp"

namespace nc {
struct SimulationConfig {
  int steps{};
  double dt{};
  double G{};
  double eps{};
  std::vector<nc::Body> bodies{};
};
}  // namespace nc

#endif