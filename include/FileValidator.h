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
        bool endOfStream() const override;


        friend bool operator==(const FileValidator&, const FileValidator&);
        FileValidator& operator=(const FileValidator&);
    protected:
        virtual bool validate(const string&) const override;
        virtual string readLine();
        virtual int findStartingLine();
        ifstream* _file;
        int _currentLine = 1;
        bool _endOfFile = false;
        string _fileName;
};
#endif // FILEVALIDATOR_H
