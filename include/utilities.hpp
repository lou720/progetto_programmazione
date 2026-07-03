#ifndef NC_UTILITIES_HPP
#define NC_UTILITIES_HPP

#include <string>

namespace nc {

int stringToInt(std::string const&, std::string const&);

double stringToDouble(std::string const&, std::string const&);

std::size_t stringToSize_t(std::string const&, std::string const&);
}  // namespace nc

#endif