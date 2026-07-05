#include "simulation.hpp"

#include <cmath>
#include <iostream>

#include "vec2.hpp"

namespace nc {

Simulation::Simulation(SimulationConfig const& c)
    : steps_{c.steps}, dt_{c.dt}, G_{c.G}, eps_{c.eps}, bodies_{c.bodies} {
  for (auto& b : bodies_) {
    b.setAcc(computeAccelerations(bodies_, b, G_, eps_));
  }
  E_ = totalEnergy(bodies_, G_, eps_);
}

void Simulation::step() {
  velocityVerlet();

  double E_new = totalEnergy(bodies_, G_, eps_);
  double err_rel = std::abs(E_new - E_) / std::abs(E_);
  if (err_rel > 5.e-2) {
    throw std::runtime_error{
        "Energia non conservata (step : E_new : err_rel): " +
        std::to_string(current_step_) + " : " + std::to_string(E_new) + " : " +
        std::to_string(err_rel)};
  }
  ++current_step_;
  E_ = E_new;
}

void Simulation::velocityVerlet() {
  // aggiorno la posizione per tutti
  for (auto& b : bodies_) {
    Vec2 r_new = b.pos() + b.vel() * dt_ + 0.5 * b.acc() * dt_ * dt_;
    b.setPos(r_new);
  }
  // calcolo accelerazione e velocità sulla nuova posizione
  std::vector<Vec2> a_new_vec{};
  std::vector<Vec2> v_new_vec{};

  a_new_vec.reserve(bodies_.size());
  v_new_vec.reserve(bodies_.size());

  for (auto& b : bodies_) {
    Vec2 a_new = computeAccelerations(bodies_, b, G_, eps_);
    Vec2 v_new = b.vel() + 0.5 * (b.acc() + a_new) * dt_;

    a_new_vec.push_back(a_new);
    v_new_vec.push_back(v_new);
  }

  for (size_t i = 0; i < bodies_.size(); ++i) {
    bodies_[i].setAcc(a_new_vec[i]);
    bodies_[i].setVel(v_new_vec[i]);
  }
}

std::vector<Body> const& Simulation::bodies() const { return bodies_; }

double Simulation::dt() const { return dt_; }

bool Simulation::finished() const { return current_step_ >= steps_; }

/*============================================================*/

Vec2 computeAccelerations(std::vector<Body> const& bodies, Body const& bi,
                          double G, double eps) {
  Vec2 a_new{};
  for (auto const& bj : bodies) {
    if (bi.id() == bj.id()) {
      continue;
    }

    Vec2 dr = bj.pos() - bi.pos();

    double dist2 = dr.norm2() + eps * eps;

    double denom = std::pow(dist2, 1.5);

    a_new += G * bj.mass() / denom * dr;
  }
  return a_new;
}

double kineticEnergy(std::vector<Body> const& bodies) {
  double sum_k_en{};
  for (auto const& b : bodies) {
    sum_k_en += .5 * b.mass() * b.vel().norm2();
  }
  return sum_k_en;
}

double potentialEnergy(std::vector<Body> const& bodies, double G, double eps) {
  double sum_u_en{};
  for (size_t i = 0; i < bodies.size(); ++i) {
    // size_t usato per evitare conversione implicita
    for (size_t j = i + 1; j < bodies.size(); ++j) {
      auto dr = bodies[i].pos() - bodies[j].pos();
      double denom = std::sqrt(dr.norm2() + eps * eps);
      sum_u_en -= G * bodies[i].mass() * bodies[j].mass() / denom;
    }
  }
  return sum_u_en;
}

double totalEnergy(std::vector<Body> const& bodies, double G, double eps) {
  return kineticEnergy(bodies) + potentialEnergy(bodies, G, eps);
}

}  // namespace nc