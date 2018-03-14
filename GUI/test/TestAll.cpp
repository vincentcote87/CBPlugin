//
// CPSC 3720
// Assignment 1
//
// Main Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the main testing function, which runs all tests.

#include <limits.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
