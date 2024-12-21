#include "pch.h"
#include "CppUnitTest.h"
#include "..\Libraries\Exercise.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;
namespace ExerciseTest
{
	TEST_CLASS(ExerciseTest)
	{
	public:

		TEST_METHOD(TaskOneTest_ValidData_Success)
		{
			RandomGenerator gen(0, 9);
			Exercise test(3, 3, gen);
			test.task1();
			Assert::IsTrue(test.getMatrix()[0][1] == 0 && test.getMatrix()[1][0] == 0 && test.getMatrix()[1][2] == 0 && test.getMatrix()[2][1] == 0);
		}
		TEST_METHOD(TaskTwoTest_ValidData_Success)
		{
			RandomGenerator gen(0, 9);
			size_t originalColumns = 3;
			Exercise test(3, 3, gen);
			test.task2();
			if (test.getMatrix().checkColumnForNull(0) || test.getMatrix().checkColumnForNull(1) || test.getMatrix().checkColumnForNull(2))
			{
				Assert::IsTrue(test.getMatrix().getColumns() > originalColumns);
			}
			else 
			{
				Assert::IsTrue(test.getMatrix().getColumns() == originalColumns);
			}
		}
	};
}
