#include "RandomGenerator.h"

miit::algebra::RandomGenerator::RandomGenerator(const int min, const int max)
{
	this->generator = std::mt19937(std::random_device{}());
	this->distribution = std::uniform_int_distribution<int>(min, max);
}

int miit::algebra::RandomGenerator::generate()
{
	return this->distribution(this->generator);
}
