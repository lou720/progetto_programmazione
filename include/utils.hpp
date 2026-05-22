#include <fstream>
#include <sstream>
#include <string>

#include "include/body.hpp"

namespace nc {
void inputConfig(int& N, double& dt, int& steps, double& G, double& eps) {
  std::ifstream file("config.txt");
  std::string line{};

  while (std::getline(file, line)) {
    // Gestisco righe vuote e commentate
    if (line.empty() || line[0] == '#') continue;

    // https://cplusplus.com/reference/string/string/find/
    auto pos = line.find("#");
    if (pos != std::string::npos) {
      line.substr(0, pos);
    }

    std::stringstream ss(line);
    std::string key{};
    ss >> key;

    if (key == "N") {
      ss >> N;
    } else if (key == "dt") {
      ss >> dt;
    } else if (key == "steps") {
      ss >> steps;
    } else if (key == "G") {
      ss >> G;
    } else if (key == "eps") {
      ss >> eps;
    } else if (key == "body") {
      int id{};
      double mass{};
      double pos_x{};
      double pos_y{};
      double vel_x{};
      double vel_y{};

      nc::Body b{id, mass, sf::Vector2{pos_x, pos_y},
                 sf::Vector2{vel_x, vel_y}};
    }
  }
}
}  // namespace nc