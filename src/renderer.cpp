#include "renderer.hpp"

namespace nc {
Renderer::Renderer(RendererConfig const& r)
    : title_{r.title}, width_{r.width}, height_{r.height}, fps_{r.fps} {}

}  // namespace nc