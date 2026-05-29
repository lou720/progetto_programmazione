// Questo main permette la simulazione solo da file di configurazione

#include <exception>
#include <iostream>

#include "configLoader.hpp"
#include "simulationConfig.hpp"
#include "app.hpp"
#include "rendererConfig.hpp"

int main() {
  try {
    // Load automatico 8-shape
    nc::SimulationConfig sim_config = nc::loadSimulation("simulation.config");
    nc::RendererConfig ren_config = nc::loadRenderer("renderer.config");

    nc::App app{sim_config, ren_config};
    
    app.run();

    return EXIT_SUCCESS;
  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}
