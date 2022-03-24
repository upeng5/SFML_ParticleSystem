#pragma once

#include <random>
#include <cmath>

inline float GenerateRandomNumber(float min, float max)
{
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_real_distribution<float> dist{ min, max };
	return dist(mt);
}

inline float GenerateRandom(float min, float max) {
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return min + fmod(rand(), ((max + 1) - min));
}