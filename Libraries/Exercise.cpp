#include "Exercise.h"
using namespace miit::algebra;
void miit::algebra::Exercise::task1()
{
	for (size_t i=0;i < matrix.getRows();i++)
	{
		for (size_t j=0;j < matrix.getColumns();j++)
		{
			if ((i + j) % 2 != 0)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void miit::algebra::Exercise::task2()
{
	size_t newSize=0;
	for (size_t i = 0;i < matrix.getColumns();i++)
	{
		if (matrix.checkColumnForNull(i))
		{
			
			newSize++;
		}
	}
	Matrix<int> temp(matrix.getRows(),matrix.getColumns()+newSize);
	size_t k = 0;
	for (size_t j = 0;j < matrix.getColumns();j++)
	{
		for (size_t i = 0;i < matrix.getRows();i++)
		{
			temp[i][k] = matrix[i][j];
		}
		k++;
		if (temp.checkColumnForNull(j))
		{
			for (int i = 0;i < matrix.getRows();i++)
			{
				temp[i][k] = matrix[i][0];
			}
			k++;
		}
	}
	matrix = temp;
}

Matrix<int> miit::algebra::Exercise::getMatrix()
{
	return matrix;
}
