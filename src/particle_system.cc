#include "particle_system.h"

#include <iostream>
#include <algorithm>

#include "random_util.h"

ParticleSystem::ParticleSystem(const sf::Vector2f& start_pos)
	: alternate_{ false }
{
	// Arbitrary number
	size_t num_particles = 20;

	particles_.resize(num_particles);

	// Init the first particle
	Particle start(10.f, sf::Color::White, start_pos);
	start.set_velocity(0.f, 0.f);
	start.set_acceleration(0.f, 0.f);

	particles_[0] = start;

	for (size_t i = 1; i < num_particles; i++)
	{
		// Generate random velocity values

		float rand_x = 0.1f;
		float rand_y = GenerateRandom(0.4f, 8.0f);
		rand_y = -rand_y;

		rand_x = (alternate_) ? -rand_x : rand_x;

		// Generate random acceleration values
		float rand_x_acc = GenerateRandomNumber(0.0f, 0.2f);

		if (alternate_) {
			rand_x_acc = -rand_x_acc;
			alternate_ = false;
		}
		else {
			alternate_ = true;
		}

		Particle particle(10.f);

		particle.set_velocity(rand_x, rand_y);
		particle.set_acceleration(rand_x_acc, 0.2f);
		particle.set_position(start_pos.x, start_pos.y);

		particles_[i] = particle;
	}
}

void ParticleSystem::Run(sf::RenderWindow& window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

	// Init particle
	Particle particle{ 12.f , sf::Color::Cyan };

	if (mouse_pos.x >= 0 && mouse_pos.y >= 0) {
		particle.set_position(mouse_pos.x, mouse_pos.y);
	}

	particles_.push_back(particle);
	for (size_t i = 0; i < particles_.size(); i++)
	{
		// Alternate directions
		if (alternate_) {
			sf::Vector2f acc = particles_[i].get_acceleration();
			particles_[i].set_acceleration(-acc.x, acc.y);
		}

		window.draw(particles_[i]);
		particles_[i].Update();

		if (particles_[i].Finished()) {
			Remove(i);
		}
	}
}

void ParticleSystem::Remove(size_t index)
{
	particles_.erase(particles_.begin() + index);
}