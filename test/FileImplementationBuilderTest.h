#ifndef FILEIMPLEMENTATIONBUILDERTEST_H
#define FILEIMPLEMENTATIONBUILDERTEST_H

#include "gtest/gtest.h"
#include "FileImplementationBuilder.h"
#include "MockFileValidator.h"

using namespace ::testing;

class FileImplemenationBuilderTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            _MockValidator = new MockFileValidator();
            _fileBuilder = new FileImplemenationBuilder(_MockValidator);
        }

        virtual void TearDown() {

        }

        ImplementationBuilder* _fileBuilder;
        MockFileValidator* _MockValidator;
};

#endif // FILEIMPLEMENTATIONBUILDERTEST_H
