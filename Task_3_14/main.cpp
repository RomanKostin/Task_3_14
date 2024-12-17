#include <iostream>
#include "..\Libraries\Matrix.h"
using namespace miit::algebra;
int main()
{
	Matrix<int> test(3,5);
	std::cout << test << std::endl;
	test.randomIntFill(-10,10);
	std::cout << std::endl << test << std::endl;
	test.istreamIntFill(std::cin);
	std::cout << std::endl << test;
	return 0;
}