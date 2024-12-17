#pragma once
#include <iostream>
#include <vector>
#include <sstream>
namespace miit::algebra
{
	template<typename T> class Matrix;

	template<typename T>
	std::ostream& operator<<(std::ostream& os,const Matrix<T>& matr);

	template<typename T>
	class Matrix
	{
	private:
		std::vector<std::vector<int>> matrix;
		int rows;
		int columns;
	public:
		Matrix(int row, int column);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other)noexcept;
		Matrix& operator =(const Matrix& other);
		Matrix& operator =(Matrix&& other) noexcept;
		std::vector<T>&operator[](int index);
		const std::vector<T>& operator[](int index) const;
		std::string ToString() const;
	};
}
template <typename T>
miit::algebra::Matrix<T>::Matrix(int row, int column) :rows{ row }, columns{ column }
{
	this->matrix.assign(row, std::vector<int>(column));
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(const Matrix& other) :matrix{ other.matrix }, rows{ other.rows }, columns{ other.columns } {}

template <typename T>
miit::algebra::Matrix<T>::Matrix(Matrix&& other)noexcept :matrix{ std::move(other.matrix) }, rows{ std::move(other.rows) }, columns{ std::move(other.columns) } {}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->matrix = other.matrix;
		this->rows = other.rows;
		this->columns = other.columns;
	}
	return *this;
}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		this->matrix = std::move(other.matrix);
		this->rows = std::move(other.rows);
		this->columns = std::move(other.columns);
	}
	return *this;
}
template <typename T>
std::vector<T>& miit::algebra::Matrix<T>::operator[](int index)
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Выход за границу");
	}
	return matrix[index];
}

template <typename T>
const std::vector<T>& miit::algebra::Matrix<T>::operator[](int index) const
{
	if (index<0 || index>rows - 1)
	{
		throw std::out_of_range("Выход за границу");
	}
	return matrix[index];
}

template <typename T>
std::string miit::algebra::Matrix<T>::ToString() const
{
	std::stringstream buffer{};
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

template <typename T>
std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix<T>& matr)
{
	os << matr.ToString();
	return os;
}

