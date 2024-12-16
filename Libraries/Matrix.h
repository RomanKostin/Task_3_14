#pragma once
#include <iostream>
#include <vector>
#include <sstream>
namespace miit::algebra
{
	class Matrix;
	std::ostream& operator<<(std::ostream& os,const Matrix& matr);
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
		std::vector<int>&operator[](int index);
		const std::vector<int>& operator[](int index) const;
		std::string ToString() const;
	};
}
