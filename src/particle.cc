#include "particle.h"
#include "random_util.h"

Particle::Particle()
	: shape_(10.f), lifespan_(255)
{
	Init();
}

Particle::Particle(float radius)
	: shape_(radius), lifespan_(255)
{
	Init();
}

Particle::Particle(float radius, const sf::Color& color)
	: shape_(radius), lifespan_(255)
{
	Init();
	shape_.setFillColor(color);
}

Particle::Particle(float radius, const sf::Color& color, const sf::Vector2f& pos)
	: shape_(radius), lifespan_(255)
{
	Init(pos);
	shape_.setFillColor(color);
}

void Particle::Move(float dx, float dy)
{
	shape_.move(dx, dy);
}

void Particle::Init(const sf::Vector2f& pos)
{
	// Default color
	shape_.setFillColor(sf::Color(245, 171, 34));

	float y_velocity = GenerateRandom(0.4f, 4.0f);
	y_velocity = -y_velocity;

	float x_acceleration = GenerateRandomNumber(0.1f, 0.3f);
	// Random Position
	shape_.setPosition(pos);

	velocity_ = sf::Vector2f(0.2f, y_velocity);
	acceleration_ = sf::Vector2f(x_acceleration, 0.2f);
}

bool Particle::Finished()
{
	if (this->lifespan_ <= 0)
		return true;
	else
		return false;
}

void Particle::Update()
{
	if (Finished()) {
		shape_.setFillColor(sf::Color::Transparent);
		return;
	}

	velocity_ = velocity_ + acceleration_;
	Move(velocity_.x, velocity_.y);

	lifespan_ -= 4;
	sf::Color curr_color = shape_.getFillColor();
	curr_color.a = lifespan_;
	shape_.setFillColor(curr_color);
}

void Particle::set_position(float x, float y)
{
	shape_.setPosition(x, y);
}

sf::Vector2f Particle::get_position() const
{
	return shape_.getPosition();
}

void Particle::set_velocity(float dx, float dy)
{
	velocity_.x = dx;
	velocity_.y = dy;
}

sf::Vector2f Particle::get_velocity()
{
	return velocity_;
}

void Particle::set_acceleration(float dx, float dy)
{
	acceleration_.x = dx;
	acceleration_.y = dy;
}

sf::Vector2f Particle::get_acceleration()
{
	return acceleration_;
}

void Particle::set_fill_color(const sf::Color& color)
{
	shape_.setFillColor(color);
}

// draw() function must be implemented for all of sf::Drawable derived classes
void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}