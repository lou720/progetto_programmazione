#include "configLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "body.hpp"
#include "simulationConfig.hpp"

namespace nc {

SimulationConfig load() {
  SimulationConfig sim_config{};

  std::ifstream file("config.txt");

  if (!file.is_open()) {
    throw std::runtime_error("Cannot open config file");
  }

  std::string line{};

  while (std::getline(file, line)) {
    // righe vuote/commenti
    if (line.empty() || line[0] == '#') continue;

    auto pos = line.find('#');

    if (pos != std::string::npos) {
      line = line.substr(0, pos);
    }

    std::stringstream ss(line);

    std::string key{};
    ss >> key;

    if (key == "N") {
      size_t N;
      ss >> N;

      sim_config.bodies.reserve(N);

    } else if (key == "dt") {
      ss >> sim_config.dt;

    } else if (key == "steps") {
      ss >> sim_config.steps;

    } else if (key == "G") {
      ss >> sim_config.G;

    } else if (key == "eps") {
      ss >> sim_config.eps;

    } else if (key == "body") {
      int id{};
      double mass{};
      double pos_x{};
      double pos_y{};
      double vel_x{};
      double vel_y{};

      ss >> id >> mass >> pos_x >> pos_y >> vel_x >> vel_y;

      sim_config.bodies.emplace_back(
          Body{id, Vec2{pos_x, pos_y}, Vec2{vel_x, vel_y}, mass});
    }
  }

  return sim_config;
}

}  // namespace nc