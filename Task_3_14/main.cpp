#include <iostream>
#include "..\Libraries\Matrix.h"
#include "..\Libraries\Exercise.h"
using namespace miit::algebra;
int main()
{
	Matrix<int> test(3,5);
	std::cout << test << std::endl;
	test.randomIntFill(-10,10);
	std::cout << std::endl << test << std::endl;
	Exercise solver(test);
	std::cout << std::endl << solver.task1();
	return 0;
}