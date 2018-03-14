#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H

#include "InterfaceValidator.h"
#include <fstream>

using std::fstream;

class FileValidator : public InterfaceValidator {
    public:
        FileValidator() {}
        FileValidator(istream*);
        FileValidator(fstream*);
        FileValidator(const fstream&);
        FileValidator(const FileValidator&);
        virtual ~FileValidator() {}
        virtual string next() override;


        friend bool operator==(const FileValidator&, const FileValidator&);
        FileValidator& operator=(const FileValidator&);
    protected:
        virtual bool validate(bool = true) const override;

    private:
        string readLine();
        int findStartingLine();
        int _currentLine = 1;
};
#endif // FILEVALIDATOR_H
