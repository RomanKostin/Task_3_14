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

		explicit ExerciseVirtual(size_t rows, size_t columns,Generator& generator);

		virtual ~ExerciseVirtual()=default;

		void Run();
	};
}