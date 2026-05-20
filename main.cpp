#include <fstream>


#include "input.hpp"
#include "body.hpp"
#include "simulation.hpp"
#include <vector>
#include <SFML/System/Vector2.hpp>

int main() {
    int steps{};
    float dt{};
    int n_particle{};
    std::vector<nc::Body> container{};
    std::vector<sf::Vector2f> r{};
    std::vector<sf::Vector2f> v{};
    std::string fileName{"file.config"};

    nc::inputFromFileConfig(fileName, steps, dt, n_particle, r, v);



    container = nc::generateBodies(container, r, v);

    nc::Simulation sim{steps, dt, container}
 
}
