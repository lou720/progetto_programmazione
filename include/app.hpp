#ifndef NC_APP_HPP
#define NC_APP_HPP

#include "renderer.hpp"
#include "rendererConfig.hpp"
#include "simulation.hpp"
#include "simulationConfig.hpp"

namespace nc {

class App {
 private:
  Simulation simulation_;
  Renderer renderer_;

 public:
  App(SimulationConfig const&, RendererConfig const&);

  void run();
};
}  // namespace nc

#endif