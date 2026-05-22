#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "simulation.hpp"

int main() {
  try {
    nc::Simulation sim{};

    std::cout << "Commands:\n"
              << "  r -r        run random simulation\n"
              << "  r --random\n"
              << "  r -c        run config simulation\n"
              << "  r --config\n"
              << "  q           quit\n";

    std::string line{};

    // TODO: il codice presente legge anche comandi come "r-c" "r-r". Da correggere!

    while (std::getline(std::cin, line)) {
      std::stringstream ss(line);
      char cmd{};
      ss >> cmd;

      if (cmd == 'r') {
        std::string flag{};

        if (ss >> flag) {
          if (flag == "-r" || flag == "--random") {
            std::cout << "Running random simulation, flag: " << flag << '\n';
            sim.run('r');
          } else if (flag == "-c" || flag == "--config") {
            std::cout << "Running simulation from file.config, flag: " << flag
                      << '\n';
            sim.run('c');
          } else {
            std::cout << "Invlid flag\n";
          }
        } else {
            std::cout << "Running simulation from file.config, NO FLAG\n";
        }

      } else if (cmd == 'q') {
        return EXIT_SUCCESS;
      } else {
        std::cout << "Unknown command\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }
  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}
