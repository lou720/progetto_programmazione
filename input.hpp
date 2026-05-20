#ifndef NC_INPUT_HPP
#define NC_INPUT_HPP

#include <string>
#include <sstream>
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace nc {
void inputFromFileConfig(std::string const& fileNameConfig, int& steps, float& dt, int& n_particle, std::vector<sf::Vector2f>& r, std::vector<sf::Vector2f>& v) {
  std::ifstream f_config{fileNameConfig};
  std::string line{};

  while (std::getline(f_config, line)) {
    std::stringstream ss(line);
    std::string key{};

    ss >> key;

    if (key == "steps") {
      ss >> steps;
    } else if (key == "dt") {
      ss >> dt;
    } else if (key == "n_particle") {
      ss >> n_particle;
    } else if(key == "r1" || key == "r2" || key == "r3") {
        float x, y;
        ss >> x >> y;
        r.push_back(sf::Vector2f{x, y});
    }
    else if(key == "v1" || key == "v2" || key == "v3") {
        float x, y;
        ss >> x >> y;
        v.push_back(sf::Vector2f{x, y});
    }
  }
}
}  // namespace nc

#endif