#pragma once
#include"Matrix.h"
namespace miit::algebra
{
	/*
	*@brief виртуальный класс задания
	*/
	class ExerciseVirtual
	{
	protected:
		/*
		*@brief матрица
		*/
		Matrix<int> matrix;

		/*
		*@brief виртуальное первое задание
		*/
		virtual void task1() = 0;

		/*
		*@brief виртуальное второе задание
		*/
		virtual void task2() = 0;

	public:

		/*
		*@brief конструктор класса виртуальное задание
		*@param rows - количество строк
		*@param columns - количество столбцов
		*@param generator - генератор
		*/
		explicit ExerciseVirtual(size_t rows, size_t columns,Generator& generator);

		/*
		*@brief деструктор виртуального задания
		*/
		virtual ~ExerciseVirtual()=default;

		/*
		*@brief метод запуска выполнения задания один и два
		*/
		void Run();
	};
}