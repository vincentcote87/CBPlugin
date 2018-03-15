#ifndef FILEIMPLEMENTATIONBUILDERTEST_H
#define FILEIMPLEMENTATIONBUILDERTEST_H

#include "gtest/gtest.h"

using namespace ::testing;

class FileImplemenationBuilderTest : public ::testing::Test {
    protected:
        virtual void SetUp() {

        }

        virtual void TearDown() {

        }

        ImplementationBuilder* _fileBuilder;
};

#endif // FILEIMPLEMENTATIONBUILDERTEST_H
