// Questo main permette la simulazione solo da file di configurazione

#include <exception>
#include <iostream>

#include "app.hpp"
#include "configLoader.hpp"
#include "rendererConfig.hpp"
#include "simulationConfig.hpp"

int main(int argc, char** argv) {
  try {
    // controllo che ci sia solo un argomento
    if (argc < 2) {
      throw std::runtime_error{"no configuration file was given"};
    } else if (argc > 2) {
      throw std::runtime_error{"too many arguments"};
    }

    // Load shape da file configurazionale
    nc::SimulationConfig sim_config = nc::loadSimulation(argv[1]);
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
