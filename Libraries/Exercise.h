#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	class Exercise :public miit::algebra::ExerciseVirtual
	{
	public:

		Exercise(int rows,int columns,Generator& generator) : ExerciseVirtual(rows,columns,generator){}

		void task1() override;

		void task2() override;

		bool checkColumnForNull(int column);
	};
}
