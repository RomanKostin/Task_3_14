#include <iostream>
#include "..\Libraries\Matrix.h"
#include "..\Libraries\Exercise.h"
using namespace miit::algebra;
int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix<int> test(3,5);
	std::cout << test << std::endl;
	RandomGenerator gen(0,9);
	test.Fill(gen);
	std::cout << std::endl << test << std::endl;
	IStreamGenerator igen(std::cin);
	//Exercise solver(test);
	//std::cout << std::endl << solver.task1();
	//for (int i = 0;i < test.getColumns();i++)
	//{
	//	if (solver.checkColumnForNull(i))
	//	{
	//		std::cout << std::endl << "метод работает в колонне " << i << std::endl;
	//	}
	//}
//	std::cout <<std::endl << solver.task2();
	return 0;
}