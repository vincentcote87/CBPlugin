#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H

#include "InterfaceValidator.h"
#include <fstream>

using std::fstream;

class FileValidator : public InterfaceValidator {
    public:
        FileValidator(fstream*);
        virtual ~FileValidator() {}
        virtual string next() override;

    protected:
        virtual bool validate(bool = true) const override;

    private:
        string readLine();
        int findStartingLine();
        int _currentLine = 1;
};
#endif // FILEVALIDATOR_H
