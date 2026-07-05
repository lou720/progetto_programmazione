#ifndef NC_APP_HPP
#define NC_APP_HPP

#include "renderer.hpp"
#include "rendererConfig.hpp"
#include "simulation.hpp"
#include "simulationConfig.hpp"
#include <SFML/Graphics.hpp>

namespace nc {

class App { 
 private:
  Simulation simulation_;
  Renderer renderer_;
  double time_scale_;
  sf::RenderWindow window_; 

 public:
  App(SimulationConfig const&, RendererConfig const&, double);

  void run();
};
}  // namespace nc

#endif