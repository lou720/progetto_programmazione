#include "app.hpp"

namespace nc {
App::App(SimulationConfig const& s, RendererConfig const& r)
    : simulation_{s}, renderer_{r} {}
}  // namespace nc