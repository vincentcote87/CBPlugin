#ifndef INTERFACEVALIDATOR_H
#define INTERFACEVALIDATOR_H

#include <istream>
#include <string>

using std::istream;
using std::string;

class InterfaceValidator {
    public:
        InterfaceValidator(istream&);
        string Next();

    private:
        istream& _interface;
        int _currentLine;
        bool validate(bool = true) const;
        string ReadLine(int) const;
};

#endif // INTERFACEVALIDATOR_H
