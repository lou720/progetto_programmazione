// Questo main permette la simulazione solo da file di configurazione

#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "configLoader.hpp"
#include "simulation.hpp"
#include "simulationConfig.hpp"

int main(int argc, char** argv) {
  try {
    // Load automatico da config.txt
    nc::SimulationConfig config = nc::load();
    
    nc::Simulation sim{config};

    sim.run();

    return EXIT_SUCCESS;
  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}
