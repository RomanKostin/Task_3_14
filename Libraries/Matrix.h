#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
namespace miit::algebra
{
	template<typename T> class Matrix;

	template<typename T>
	std::ostream& operator<<(std::ostream& os,const Matrix<T>& matr);

	template<typename T>
	class Matrix
	{
	private:
		std::vector<std::vector<T>> matrix;
		size_t rows;
		size_t columns;
	public:
		Matrix() = default;
		Matrix(size_t row, size_t column);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other)noexcept;
		Matrix& operator =(const Matrix& other);
		Matrix& operator =(Matrix&& other) noexcept;
		~Matrix() = default;
		std::vector<T>&operator[](size_t index);
		const std::vector<T>& operator[](size_t index) const;
		std::string ToString() const;
		void Fill(Generator& generator);
		size_t getRows();
		size_t getColumns();
	};
}
template <typename T>
miit::algebra::Matrix<T>::Matrix(size_t row, size_t column)
{
	rows = row; 
	columns = column;
	this->matrix.assign(row, std::vector<T>(column));
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
std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index)
{
	return matrix[index];
}

template <typename T>
const std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index) const
{
	return matrix[index];
}

template <typename T>
std::string miit::algebra::Matrix<T>::ToString() const
{
	std::stringstream buffer{};
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

template<typename T>
inline void miit::algebra::Matrix<T>::Fill(Generator& generator)
{
	for (size_t i = 0;i < rows;i++)
	{
		for (size_t j = 0; j < columns;j++)
		{
			matrix[i][j] = generator.generate();
		}
	}
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::getRows()
{
	return rows;
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::getColumns()
{
	return columns;
}

template <typename T>
std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix<T>& matr)
{
	os << matr.ToString();
	return os;
}

