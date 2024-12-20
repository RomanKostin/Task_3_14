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
		Matrix(int row, int column);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other)noexcept;
		Matrix& operator =(const Matrix& other);
		Matrix& operator =(Matrix&& other) noexcept;
		~Matrix() = default;
		std::vector<T>&operator[](int index);
		const std::vector<T>& operator[](int index) const;
		std::string ToString() const;
	//	void randomIntFill(int min,int max);
	//	void istreamIntFill(std::istream& in);
		void Fill(Generator& generator);
		int getRows();
		int getColumns();
	};
}
template <typename T>
miit::algebra::Matrix<T>::Matrix(int row, int column)
{
	if (row < 0 || column < 0)
	{
		throw std::out_of_range("Выход за границу");
	}
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

//template<typename T>
//inline void miit::algebra::Matrix<T>::randomIntFill(int min, int max)
//{
//	RandomGenerator generator(min,max);
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < columns; j++)
	//	{
	//		matrix[i][j] = generator.generate();
	//	}
	//}
//}

//template<typename T>
//inline void miit::algebra::Matrix<T>::istreamIntFill(std::istream& in)
//{
//	IStreamGenerator generator(in);
//	for (size_t i = 0; i < rows; i++)
//	{
//		for (size_t j = 0; j < columns; j++)
//		{
//			matrix[i][j] = generator.generate();
//		}
//	}
//}

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
inline int miit::algebra::Matrix<T>::getRows()
{
	return rows;
}

template<typename T>
inline int miit::algebra::Matrix<T>::getColumns()
{
	return columns;
}

template <typename T>
std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix<T>& matr)
{
	os << matr.ToString();
	return os;
}

