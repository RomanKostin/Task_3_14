#pragma once
#include"Matrix.h"
namespace miit::algebra
{
	class ExerciseVirtual
	{
	protected:

		Matrix<int> matrix;

		virtual void task1() = 0;

		virtual void task2() = 0;

	public:

		explicit ExerciseVirtual(int rows, int columns,Generator& generator);

		virtual ~ExerciseVirtual()=default;
	};
}