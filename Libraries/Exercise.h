#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	/*
	*@brief класс задание, наследник виртуального задания
	*/
	class Exercise :public miit::algebra::ExerciseVirtual
	{
	public:

		/*
		*@brief конструктор класса задание
		*@param rows - количество строк
		*@param columns - количество столбцов
		*@param generator - генератор
		*/
		Exercise(size_t rows, size_t columns,Generator& generator) : ExerciseVirtual(rows,columns,generator){}

		/*
		*@brief задание один, меняет все элементы с нечетными индексами на нули
		*/
		void task1() override;

		/*
		*@brief задание два, вставляет после каждого столбца с нулем первый столбец
		*/
		void task2() override;

		/*
		*@brief геттер матрицы
		*@return матрица из задания
		*/
		Matrix<int> getMatrix();

	};
}
