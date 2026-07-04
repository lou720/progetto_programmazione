#include "configLoader.hpp"

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>

#include "body.hpp"
#include "rendererConfig.hpp"
#include "simulationConfig.hpp"
#include "utilities.hpp"

namespace nc {

SimulationConfig loadSimulation(std::string const& path) {
  std::map<std::string, bool> initialized_values{
      {"N", false}, {"dt", false},  {"steps", false},
      {"G", false}, {"eps", false}, {"body", false}};
  
  size_t expetetd_size{};

  SimulationConfig sim_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("File non aperto: " + path);
  }

  std::string line{};
  int nline{};

  while (std::getline(file, line)) {
    ++nline;
    // righe vuote/commenti
    if (line.empty() || line[0] == '#') {
      continue;
    }

    auto pos = line.find('#');

    if (pos != std::string::npos) {
      line = line.substr(0, pos);
    }

    if (line.find_first_not_of(" ") == std::string::npos) {
      continue;
    }

    std::stringstream ss(line);

    std::string key{};
    ss >> key;

    if (key == "N") {
      std::string N_string;
      ss >> N_string;
      try {
        expetetd_size = stringToSize_t(N_string, key);
        sim_config.bodies.reserve(expetetd_size);
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else if (key == "dt") {
      std::string dt_str{};
      ss >> dt_str;
      try {
        sim_config.dt = stringToDouble(dt_str, key);
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else if (key == "steps") {
      std::string steps_str{};
      ss >> steps_str;
      try {
        sim_config.steps = stringToInt(steps_str, key);
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else if (key == "G") {
      std::string G_str{};
      ss >> G_str;
      try {
        sim_config.G = stringToDouble(G_str, key);
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else if (key == "eps") {
      std::string eps_str{};
      ss >> eps_str;
      try {
        sim_config.eps = stringToDouble(eps_str, key);
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else if (key == "body") {
      std::string id_str{};
      std::string mass_str{};
      std::string pos_x_str{};
      std::string pos_y_str{};
      std::string vel_x_str{};
      std::string vel_y_str{};

      ss >> id_str >> mass_str >> pos_x_str >> pos_y_str >> vel_x_str >>
          vel_y_str;
      try {
        sim_config.bodies.emplace_back(
            Body{stringToInt(id_str, key),
                 Vec2{stringToDouble(pos_x_str, key),
                      stringToDouble(pos_y_str, key)},
                 Vec2{stringToDouble(vel_x_str, key),
                      stringToDouble(vel_y_str, key)},
                 stringToDouble(mass_str, key)});
        initialized_values[key] = true;
      } catch (std::runtime_error const& e) {
        throw std::runtime_error{"Riga " + std::to_string(nline) + " " + e.what()};
      }

    } else {
      throw std::runtime_error{std::string{"Riga " + std::to_string(nline) +
                                           " key non riconosciuta: " + key}};
    }
  }

  for (auto const& p : initialized_values) {
    if (p.second == false) {
      throw std::runtime_error{"Key non inizializzata: " + p.first};
    }
  }

  if (expetetd_size != sim_config.bodies.size()) {
    throw std::runtime_error{"Il numero di corpi dichiarati non corrisponde a quello dei corpi definiti"};
  }

  return sim_config;
}

RendererConfig loadRenderer(std::string const& path) {
  RendererConfig ren_config{};

  std::ifstream file(path);

  if (!file.is_open()) {
    throw std::runtime_error("File non aperto: " + path);
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