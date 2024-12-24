#pragma once

namespace miit::algebra
{
	/*
	*@brief виртуальный класс генератор
	*/
	class Generator
	{
	public:
		/*
		*@brief виртуальный деструктор класса генератор
		*/
		virtual ~Generator() = 0 {};

		/*
		*@brief виртуальный метод генерации значения
		*/
		virtual int generate() = 0;
	};
}
