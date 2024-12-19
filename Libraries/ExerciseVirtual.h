#pragma once
#include"Matrix.h"
namespace miit::algebra
{
	class ExerciseVirtual
	{
	protected:

		Matrix<int> matrix;

		virtual Matrix<int> task1() = 0;

		virtual Matrix<int> task2() = 0;

	public:

		explicit ExerciseVirtual(Matrix<int> matr) :matrix{matr} {}

		virtual ~ExerciseVirtual()=default;
	};
}