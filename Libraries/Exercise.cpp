#include "Exercise.h"
using namespace miit::algebra;
Matrix<int> miit::algebra::Exercise::task1()
{
	Matrix<int> temp(matrix);
	for (int i=0;i < temp.getRows();i++)
	{
		for (int j=0;j < temp.getColumns();j++)
		{
			if ((i + j) % 2 != 0)
			{
				temp[i][j] = 0;
			}
		}
	}
	return temp;
}
