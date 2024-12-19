#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	class Exercise :public miit::algebra::ExerciseVirtual
	{
	public:

		Exercise(Matrix<int> matr) : ExerciseVirtual(matr){}

		Matrix<int> task1() override;

		Matrix<int> task2() override;
	};
}
