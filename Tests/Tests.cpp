#include "pch.h"
#include "CppUnitTest.h"
#include "..\Libraries\Matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;
namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(MatrixCtor_ValidData_Success)
		{
			Matrix<int> test(1,1);
			Assert::IsTrue(test[0][0]==0);
		}
		TEST_METHOD(MatrixCopyCtor_ValidData_Success)
		{
			Matrix<int> test(3, 3);
			Matrix<int> copyTest(test);
			Assert::AreEqual(test.ToString(),copyTest.ToString());
		}
		TEST_METHOD(MatrixMoveCtor_ValidData_Success)
		{
			Matrix<int> test(1,1);
			Matrix<int> moveTest(std::move(test));
			Assert::IsTrue(moveTest[0][0] == 0);
		}
		TEST_METHOD(MatrixOperatorEqual_ValidData_Success)
		{
			Matrix<int> test(3, 3);
			Matrix<int> equalTest = test;
			Assert::AreEqual(test.ToString(),equalTest.ToString());
		}
		TEST_METHOD(MatrixOperatorEqualMove_ValidData_Success)
		{
			Matrix<int> test(1, 1);
			Matrix<int> moveTest=std::move(test);
			Assert::IsTrue(moveTest[0][0] == 0);
		}
		TEST_METHOD(MatrixOperatorIterator_ValidData_Success)
		{
			Matrix<int> actual(1, 3);
			std::vector<int> expected{0,0,0};
			Assert::IsTrue(actual[0]== expected);
		}
		TEST_METHOD(MatrixGetRows_ValidData_Success)
		{
			Matrix<int> test(3, 1);
			size_t rows = 3;
			Assert::AreEqual(test.getRows(),rows);
		}
		TEST_METHOD(MatrixGetColumns_ValidData_Success)
		{
			Matrix<int> test(1, 3);
			size_t columns = 3;
			Assert::AreEqual(test.getColumns(), columns);
		}
		TEST_METHOD(MatrixCheckForNull_ValidData_Success)
		{
			Matrix<int> test(3, 3);
			Assert::IsTrue(test.checkColumnForNull(0));
			Assert::IsTrue(test.checkColumnForNull(1));
			Assert::IsTrue(test.checkColumnForNull(2));
		}
	};
}
