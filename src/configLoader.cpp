#include "configLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "body.hpp"
#include "rendererConfig.hpp"
#include "simulationConfig.hpp"
#include "utilities.hpp"

namespace nc {

SimulationConfig loadSimulation(std::string const& path) {
  // non controlla la correttezza dei dati
  SimulationConfig sim_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("Cannot open " + path);
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
      std::string N_string;
      ss >> N_string;
      sim_config.bodies.reserve(stringToSize_t(N_string, key));

    } else if (key == "dt") {
      std::string dt_str{};
      ss >> dt_str;
      sim_config.dt = stringToDouble(dt_str, key);

    } else if (key == "steps") {
      std::string steps_str{};
      ss >> steps_str;
      sim_config.steps = stringToInt(steps_str, key);

    } else if (key == "G") {
      std::string G_str{};
      ss >> G_str;
      sim_config.G = stringToInt(G_str, key);

    } else if (key == "eps") {
      std::string eps_str{};
      ss >> eps_str;
      sim_config.eps = stringToDouble(eps_str, key);

    } else if (key == "body") {
      std::string id_str{};
      std::string mass_str{};
      std::string pos_x_str{};
      std::string pos_y_str{};
      std::string vel_x_str{};
      std::string vel_y_str{};

      ss >> id_str >> mass_str >> pos_x_str >> pos_y_str >> vel_x_str >>
          vel_y_str;

      std::string key_id = key + ' ' + id_str;

      sim_config.bodies.emplace_back(
          Body{stringToInt(id_str, key_id+" id"),
               Vec2{stringToDouble(pos_x_str, key_id+" pos_x"),
                    stringToDouble(pos_y_str, key_id+" pos_y")},
               Vec2{stringToDouble(vel_x_str, key_id+" vel_x"),
                    stringToDouble(vel_y_str, key_id+" vel_y")},
               stringToDouble(mass_str, key_id+" mass")});
    }
  }

  return sim_config;
}

RendererConfig loadRenderer(std::string const& path) {
  RendererConfig ren_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("Cannot open " + path);
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