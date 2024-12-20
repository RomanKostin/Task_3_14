#include "ExerciseVirtual.h"

miit::algebra::ExerciseVirtual::ExerciseVirtual(int rows, int columns,Generator& generator)
{
	this->matrix = Matrix<int>{ rows, columns };
	matrix.Fill(generator);
}
