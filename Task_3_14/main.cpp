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
	Exercise task(3, 5, gen);
	task.Run();
	return 0;
}