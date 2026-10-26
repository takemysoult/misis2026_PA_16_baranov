#include "CppUnitTest.h"
#include "../header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1Tests
{
    TEST_CLASS(Task1Tests)
    {
    public:
        TEST_METHOD(ProjectIsConnected)
        {
            Assert::IsTrue(true);
        }
    };
}
