// Questo main permette la simulazione solo da file di configurazione

#include <exception>
#include <iostream>

#include "app.hpp"
#include "configLoader.hpp"
#include "rendererConfig.hpp"
#include "simulationConfig.hpp"
#include "utilities.hpp"

int main(int argc, char** argv) {
  try {
    // controllo che ci sia solo un argomento
    if (argc < 2) {
      throw std::runtime_error{"Nessun file di configurazione selezionato"};
    } else if (argc > 3) {
      throw std::runtime_error{"Troppi argomenti"};
    }

    // Load shape da file configurazionale
    nc::SimulationConfig sim_config = nc::loadSimulation(argv[1]);
    nc::RendererConfig ren_config = nc::loadRenderer("config/renderer.config");
    double time_scale{1.}; // default 1 secondo reale = 1 secondo simulato  

     if (argc == 3) {
      time_scale = nc::stringToDouble(argv[2], "time_scale");
      if (!( 0 < time_scale && time_scale < 10 )) {
        throw std::runtime_error{"time_scale deve essere compreso tra 0 e 10 esclusi"};
      }
    }

    nc::App app{sim_config, ren_config, time_scale};

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
