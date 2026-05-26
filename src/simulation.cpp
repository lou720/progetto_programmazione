#include "simulation.hpp"

#include <cmath>
#include <iostream>

#include "vec2.hpp"

namespace nc {

Simulation::Simulation(SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {}

void Simulation::run() {
  for (int i{1}; i != steps_; ++i) {
    velocityVerlet();
    std::cout << i << ',' << totalEnergy() << '\n';
  };
}

void Simulation::velocityVerlet() {
  // aggiorno la posizione per tutti
  for (auto& b : bodies_) {
    Vec2 r_new = b.pos() + b.vel() * dt_ + 0.5 * b.acc() * dt_ * dt_;
    b.pos(r_new);
  }
  // calcolo accelerazione e velocità sulla nuova posizione
  for (auto& bi : bodies_) {
    Vec2 a_new{};

    for (auto const& bj : bodies_) {
      if (bi.id() == bj.id()) {
        continue;
      }

      Vec2 dr = bj.pos() - bi.pos();

      double dist2 = dr.norm2() + eps_ * eps_;

      double denom = std::pow(dist2, 1.5);  // inefficiente

      a_new += G_ * bj.mass() / denom * dr;
    }

    Vec2 v_new = bi.vel() + 0.5 * (bi.acc() + a_new) * dt_;

    bi.acc(a_new);  // potrebbe dare problemi perché i corpi
    bi.vel(v_new);  // successivi si aggiornano con i nuovi valori di
                    // accelerazione e velocità
    // soluzione:
    // std::vector<Vec2> a_new_vec{};
    // std::vector<Vec2> v_new_vec{};
    // push_back di accelerazioni e velocità nuove e aggiornamento fuori dal
    // ciclo
  }
}

double Simulation::kineticEnergy() const {
  double sum_k_en{};
  for (auto const& b : bodies_) {
    sum_k_en += .5 * b.mass() * b.vel().norm2();
  }
  return sum_k_en;
}

double Simulation::potentialEnergy() const {
  double sum_u_en{};
  for (auto const& bi : bodies_) {
    for (auto const& bj : bodies_) {
      if (bi.id() == bj.id()) {
        continue;
      }
      Vec2 dr = bi.pos() - bj.pos();
      sum_u_en += G_ * bi.mass() * bj.mass() / dr.norm();
    }  // dovrei fare softening come in velocityVerlet()?
  }
  return -sum_u_en;
}

double Simulation::totalEnergy() const {
  return kineticEnergy() + potentialEnergy();
}

}  // namespace nc