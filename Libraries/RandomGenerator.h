#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
	/*
	*@brief класс генератора случайных чисел
	*/
	class RandomGenerator : public Generator
	{
	private:
		std::uniform_int_distribution<int> distribution;
		std::mt19937 generator;

	public:
		/*
		*@brief конструктор генератора случайных чисел
		*@param min - минимальное возможное случайное значение
		*@param max - максимальное возможное случайное значение
		*/
		RandomGenerator(const int min, const int max);

		/*
		*@brief возвращает случайное целочисленное значение из заданного диапазона
		*@return случайное число
		*/
		int generate() override;
	};
}
