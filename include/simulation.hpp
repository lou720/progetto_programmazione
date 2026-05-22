#include <vector>
#include "include/body.hpp"

namespace nc {
class Simulation {
  int steps{};
  double dt{};
  double G{};
  double eps{};
  std::vector<Body> bodies{};

 public:
  void run(char mode) {
    if (mode == 'c') {    }
  }

};
}  // namespace nc