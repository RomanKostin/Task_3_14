#include "ExerciseVirtual.h"

miit::algebra::ExerciseVirtual::ExerciseVirtual(size_t rows, size_t columns,Generator& generator)
{
	this->matrix = Matrix<int>{ rows, columns };
	matrix.Fill(generator);
}

void miit::algebra::ExerciseVirtual::Run()
{
	task1();
	std::cout << matrix;
	task2();
	std::cout << std::endl << matrix;
}
