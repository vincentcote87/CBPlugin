#ifndef MOCKFILEVALIDATOR_H
#define MOCKFILEVALIDATOR_H
#include "gmock/gmock.h"
#include "FileValidator.h"

class MockFileValidator : public FileValidator {
    public:
        MOCK_METHOD0(next, string());
        MOCK_CONST_METHOD1(validate, bool(bool));
        MOCK_METHOD0(readLine, string());
        MOCK_METHOD0(findStartingLine, int());
};
#endif // MOCKFILEVALIDATOR_H
