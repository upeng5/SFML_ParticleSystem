#pragma once

#include <SFML/Graphics.hpp>

class Particle : public sf::Drawable
{
public:
	Particle();
	Particle(float radius);
	Particle(float radius, const sf::Color& color);
	Particle(float radius, const sf::Color& color, const sf::Vector2f& pos);

	bool Finished();
	void Update();

	// Setter & Getters
	void set_position(float x, float y);
	sf::Vector2f get_position() const;
	void set_velocity(float dx, float dy);
	sf::Vector2f get_velocity();
	void set_acceleration(float dx, float dy);
	sf::Vector2f get_acceleration();
	void set_fill_color(const sf::Color& color);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Move(float dx, float dy);
	void Init(const sf::Vector2f& pos = sf::Vector2f(400.f, 100.f));
	sf::CircleShape shape_;
	sf::Vector2f velocity_;
	sf::Vector2f acceleration_;
	int lifespan_;
};