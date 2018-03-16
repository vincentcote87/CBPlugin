#include "gtest/gtest.h"
#include "FileImplementationBuilderTest.h"

TEST_F(FileImplemenationBuilderTest, constructorTest) {
    EXPECT_EQ("", _fileBuilder -> build("testFile.h"));
}
