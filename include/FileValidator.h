#ifndef FILEVALIDATOR_H
#define FILEVALIDATOR_H

#include "InterfaceValidator.h"
#include <fstream>

using std::ifstream;


class FileValidator : public InterfaceValidator {
    public:
        FileValidator() {}
        FileValidator(istream*);
        FileValidator(ifstream*);
        FileValidator(const ifstream&);
        FileValidator(const string&);
        FileValidator(const FileValidator&);
        virtual ~FileValidator() {}
        virtual string next() override;
        virtual void setInterface(const string&) override;

        friend bool operator==(const FileValidator&, const FileValidator&);
        FileValidator& operator=(const FileValidator&);
    protected:
        virtual bool validate(bool = true) const override;
        virtual string readLine();
        virtual int findStartingLine();
        ifstream* _file;
        int _currentLine = 1;
};
#endif // FILEVALIDATOR_H
