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
	int newSize=0;
	for (int i = 0;i < matrix.getColumns();i++)
	{
		if (checkColumnForNull(i))
		{
			
			newSize++;
		}
	}
	Matrix<int> temp(matrix.getRows(),matrix.getColumns()+newSize);
	int k = 0;
	for (int j = 0;j < matrix.getColumns();j++)
	{
		for (int i = 0;i < matrix.getRows();i++)
		{
			temp[i][k] = matrix[i][j];
		}
		k++;
		if (checkColumnForNull(j))
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

bool miit::algebra::Exercise::checkColumnForNull(int column)
{
	for (int i=0;i<matrix.getRows();i++)
	{
		if (matrix[i][column] == 0)
		{
			return true;
		}
	}
	return false;
}
