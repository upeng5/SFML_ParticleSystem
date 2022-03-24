#pragma once

#include "particle.h"

#include <vector>

class ParticleSystem
{
public:
	ParticleSystem(const sf::Vector2f& start_pos);
	void Run(sf::RenderWindow& window);
private:
	std::vector<Particle> particles_;
	bool alternate_;
	void Remove(size_t index);
};
