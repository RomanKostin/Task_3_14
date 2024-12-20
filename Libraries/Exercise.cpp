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

Matrix<int> miit::algebra::Exercise::task2()
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
	return temp;
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
