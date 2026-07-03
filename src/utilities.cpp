#include "utilities.hpp"
#include <stdexcept>

namespace nc {

int stringToInt(std::string const& s, std::string const& key) {
  std::size_t sz{};
  try {
    int value = std::stoi(s, &sz);
    if (s.size() != sz) {
      throw std::runtime_error{"Valore in input non valido: " + key};
    }
    return value;
  } catch (std::invalid_argument const&) {
    throw std::runtime_error{"Valore in input non valido: " + key};
  } catch (std::out_of_range const&) {
    throw std::runtime_error{"Valore in input fuori dal limite: " + key};
  }
}

double stringToDouble(std::string const& s, std::string const& key) {
  std::size_t sz{};
  try {
    double value = std::stod(s, &sz);
    if (s.size() != sz) {
      throw std::runtime_error{"Valore in input non valido: " + key};
    }
    return value;
  } catch (std::invalid_argument const& e) {
    throw std::runtime_error{"Valore in input non valido: " + key};
  } catch (std::out_of_range const& e) {
    throw std::runtime_error{"Valore in input fuori dal limite: " + key};
  }
}

size_t stringToSize_t(std::string const& s, std::string const& key) {
  std::size_t sz{};
  try {
    size_t value = static_cast<size_t>(std::stoul(s, &sz));
    if (s.size() != sz) {
      throw std::runtime_error{"Valore in input non valido: " + key};
    }
    return value;
  } catch (std::invalid_argument const& e) {
    throw std::runtime_error{"Valore in input non valido: " + key};
  } catch (std::out_of_range const& e) {
    throw std::runtime_error{"Valore in input fuori dal limite: " + key};
  }
}
}  // namespace nc