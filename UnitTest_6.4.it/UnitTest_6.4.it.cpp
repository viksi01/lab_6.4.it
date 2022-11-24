#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6.4_1/lab_6.4_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double* a = new double[5];
			a[0] = -3.;
			a[1] = 8.9;
			a[2] = 30.;
			a[3] = -5.;
			a[4] = 45.;

			double p = Product(a, 5);
            Assert::AreEqual(p, 15.);


		}
	};
}
