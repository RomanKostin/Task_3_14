#include <iostream>
#include "..\Libraries\Matrix.h"
using namespace miit::algebra;
int main()
{
	Matrix<int> test(3,5);
	std::cout << test;
	return 0;
}