#ifndef NC_SIMULATION_HPP
#define NC_SIMULATION_HPP

#include <vector>
#include "include/body.hpp"

namespace nc {
class Simulation {
  private:
  int steps_{};
  double dt_{};
  double G_{};
  double eps_{};
  std::vector<nc::Body> bodies_{};

 public:
  void run();

};
}  // namespace nc
#endif