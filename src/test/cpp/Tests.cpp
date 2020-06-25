#include "gtest/gtest.h"
#include "report/ReportGenerator.h"

using namespace std;

void main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}
