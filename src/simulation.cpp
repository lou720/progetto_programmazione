#include "simulation.hpp"

#include <cmath>
#include <iostream>

#include "vec2.hpp"

namespace nc {

Simulation::Simulation(SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {}

void Simulation::run() {
  for (int i = 0; i < steps_; ++i) {
    velocityVerlet();
    // std::cout << bodies_[0].pos().x << ' ' << bodies_[0].pos().y << '\n';
    std::cout << potentialEnergy() << ' ' << kineticEnergy() << ' '
              << totalEnergy() << '\n';
  };
}

void Simulation::velocityVerlet() {
  // aggiorno la posizione per tutti
  for (auto& b : bodies_) {
    Vec2 r_new = b.pos() + b.vel() * dt_ + 0.5 * b.acc() * dt_ * dt_;
    b.pos(r_new);
  }
  // calcolo accelerazione e velocità sulla nuova posizione
  std::vector<Vec2> a_new_vec{};
  std::vector<Vec2> v_new_vec{};

  a_new_vec.reserve(bodies_.size());
  v_new_vec.reserve(bodies_.size());

  for (auto& b : bodies_) {
    Vec2 a_new = computeAccelerations(b);
    Vec2 v_new = b.vel() + 0.5 * (b.acc() + a_new) * dt_;

    a_new_vec.push_back(a_new);
    v_new_vec.push_back(v_new);
  }

  for (size_t i = 0; i < bodies_.size(); ++i) {
    bodies_[i].acc(a_new_vec[i]);
    bodies_[i].vel(v_new_vec[i]);
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
  for (size_t i = 0; i < bodies_.size(); ++i) {
    // size_t usato per evitare conversione implicita
    for (size_t j = i + 1; j < bodies_.size(); ++j) {
      auto dr = bodies_[i].pos() - bodies_[j].pos();
      sum_u_en -= G_ * bodies_[i].mass() * bodies_[j].mass() / dr.norm();
      // si potrebbe fare softening con eps
    }
  }
  return sum_u_en;
}

double Simulation::totalEnergy() const {
  return kineticEnergy() + potentialEnergy();
}

Vec2 Simulation::computeAccelerations(Body const& bi) {
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
  return a_new;
}

}  // namespace nc