#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "particle_system.h"
#include "random_util.h"

const size_t WIDTH = 800;
const size_t HEIGHT = 600;

int main()
{
	sf::Color orange(245, 171, 34);

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Particles");

	sf::Vector2f start_pos(WIDTH / 2, (HEIGHT / 2) - 100);

	// Init the particle system with the start paticle position
	ParticleSystem ps(start_pos);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::Escape) {
					window.close();
					break;
				}
			default:
				break;
			}
		}

		window.clear();

		// Render particles here
		ps.Run(window);

		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return 0;
}