#ifndef RENDERER_CONFIG_HPP
#define RENDERER_CONFIG_HPP

#include <string>

namespace nc {

// i dati sono momentaneamente hardly-type
// in futuro si potrà fare un file renderer.config
struct RendererConfig {
  std::string title{"N-Body Simulator"};
  unsigned int width{800};
  unsigned int height{600};
  unsigned int fps{60};
};

}  // namespace nc
#endif