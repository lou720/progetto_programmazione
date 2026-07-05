#ifndef RENDERER_CONFIG_HPP
#define RENDERER_CONFIG_HPP

#include <string>

namespace nc {

// i dati sono momentaneamente hardly-type
// in futuro si potrà fare un file renderer.config
struct RendererConfig {
  std::string title{};
  unsigned int width{};
  unsigned int height{};
  unsigned int fps{};
  float radius{};
};

}  // namespace nc
#endif