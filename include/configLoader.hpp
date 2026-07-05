#ifndef NC_CONFIG_LOADER_HPP
#define NC_CONFIG_LOADER_HPP

#include <string>

#include "rendererConfig.hpp"
#include "simulationConfig.hpp"

namespace nc {

SimulationConfig loadSimulation(std::string const&);

RendererConfig loadRenderer(std::string const&);

std::string errorMessage(std::string const& path, int nline = -1);

}  // namespace nc

#endif