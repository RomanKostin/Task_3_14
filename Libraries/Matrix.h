#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
namespace miit::algebra
{
	/*
	*@brief класс матрица
	*/
	template<typename T> class Matrix;

	/*
	*@brief оператор "<<" дл¤ класса матрица
	*@tparam T - тип данных в матрице
	*@param os - поток вывода
	*@param matr - матрица
	*@return измененный поток вывода
	*/
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
		/*
		*@brief конструктор матрицы без параметров
		*/
		Matrix() = default;

		/*
		*@brief конструктор матрицы по количеству строк и столбцов
		*@param row - строки
		*@param column - столбцы
		*/
		Matrix(size_t row, size_t column);

		/*
		*@brief конструктор копировани¤ дл¤ матрицы
		*@param other - друга¤ матрица
		*/
		Matrix(const Matrix& other);

		/*
		*@brief конструктор перемещением дл¤ матрицы
		*@param other - перемещаема¤ матрица
		*/
		Matrix(Matrix&& other)noexcept;

		/*
		*@brief оператор "=" дл¤ класса матрица
		*@param other - друга¤ матрица
		*/
		Matrix& operator =(const Matrix& other);

		/*
		*@brief оператор "=" перемещением дл¤ матрицы
		*@param other - перемещаема¤ матрица
		*/
		Matrix& operator =(Matrix&& other) noexcept;

		/*
		*@brief деструктор матрицы
		*/
		~Matrix() = default;

		/*
		*@brief оператор "[]" дл¤ класса матрица
		*@param index - индекс возвращаемого вектора/строки
		*@return вектор
		*/
		std::vector<T>&operator[](size_t index);

		/*
		*@brief константный оператор "[]" дл¤ класса матрица 
		*@param index - индекс возвращаемого вектора/строки
		*@return вектор
		*/
		const std::vector<T>& operator[](size_t index) const;

		/*
		*@brief метод вывода матрицы в строку
		*@return матрица в виде строки
		*/
		std::string ToString() const;

		/*
		*@brief метод заполнени¤ матрицы через генераторы
		*@param generator - генератор
		*/
		void Fill(Generator& generator);

		/*
		*@brief геттер строк матрицы
		*@return строки матрицы
		*/
		size_t getRows();

		/*
		*@brief геттер столбцов матрицы
		*@return столбцы матрицы
		*/
		size_t getColumns();

		/*
		*@brief метод проверки столбца матрицы на наличие нул¤
		*@param column - индекс провер¤емого столбца
		*@return true, если столбец содержит нуль, иначе false
		*/
		bool checkColumnForNull(size_t column);
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

template <typename T>
bool miit::algebra::Matrix<T>::checkColumnForNull(size_t column)
{
	for (size_t i = 0; i < rows; i++)
	{
		if (matrix[i][column] == 0)
		{
			return true;
		}
	}
	return false;
}
