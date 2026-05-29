#include "configLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "body.hpp"
#include "rendererConfig.hpp"
#include "simulationConfig.hpp"

namespace nc {

SimulationConfig loadSimulation(std::string const& path) {
  // non controlla la correttezza dei dati
  SimulationConfig sim_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("Cannot open " + path + " \n");
  }

  std::string line{};

  while (std::getline(file, line)) {
    // righe vuote/commenti
    if (line.empty() || line[0] == '#') {
      continue;
    }

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

RendererConfig loadRenderer(std::string const& path) {
  RendererConfig ren_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("Cannot open " + path + "\n");
  }

  std::string line{};

  while (std::getline(file, line)) {
    // righe vuote/commenti
    if (line.empty() || line[0] == '#') {
      continue;
    }

    auto pos = line.find('#');

    if (pos != std::string::npos) {
      line = line.substr(0, pos);
    }

    std::stringstream ss(line);

    std::string key{};
    ss >> key;

    if (key == "title") {
      std::getline(ss, ren_config.title);

    } else if (key == "width") {
      ss >> ren_config.width;

    } else if (key == "height") {
      ss >> ren_config.height;

    } else if (key == "fps") {
      ss >> ren_config.fps;

    } else if (key == "physics_substeps") {
      ss >> ren_config.physics_substeps;

    } else if (key == "radius") {
      ss >> ren_config.radius;
    }
  }

  return ren_config;
}

}  // namespace nc