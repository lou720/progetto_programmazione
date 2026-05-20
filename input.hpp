#ifndef NC_INPUT_HPP
#define NC_INPUT_HPP

#include <string>
#include <sstream>

namespace nc {
void inputFromFileConfig(std::string const& fileNameConfig) {
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
    }
  }
}
}  // namespace nc

#endif