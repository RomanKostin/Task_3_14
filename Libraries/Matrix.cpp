#include "Matrix.h"

miit::algebra::Matrix::Matrix(int row, int column) :rows{ row }, columns{column}
{
	this->matrix.assign(row, std::vector<int>(column));
}

miit::algebra::Matrix::Matrix(const Matrix& other):matrix{ other.matrix }, rows{ other.rows }, columns{ other.columns } {}

miit::algebra::Matrix::Matrix(Matrix&& other)noexcept :matrix{ std::move(other.matrix) }, rows{ std::move(other.rows) }, columns{ std::move(other.columns) }{}

miit::algebra::Matrix& miit::algebra::Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->matrix = other.matrix;
		this->rows = other.rows;
		this->columns = other.columns;
	}
	return *this;
}

miit::algebra::Matrix& miit::algebra::Matrix::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		this->matrix = std::move(other.matrix);
		this->rows = std::move(other.rows);
		this->columns = std::move(other.columns);
	}
	return *this;
}

std::vector<int>& miit::algebra::Matrix::operator[](int index)
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Выход за границу");
	}
	return matrix[index];
}

const std::vector<int>& miit::algebra::Matrix::operator[](int index) const
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Выход за границу");
	}
	return matrix[index];
}

std::string miit::algebra::Matrix::ToString() const
{
	std::stringstream buffer{};
	for(int i=0;i<rows;i++)
	{
		for (int j = 0; j < columns;j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix& matr)
{
	os << matr.ToString();
	return os;
}
