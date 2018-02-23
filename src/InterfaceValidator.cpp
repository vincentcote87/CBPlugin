#include "InterfaceValidator.h"

InterfaceValidator::InterfaceValidator(istream& interface) : _interface{interface} {}

string InterfaceValidator::Next() {
    if(validate()){
        return ReadLine(_currentLine);
    }
}

bool InterfaceValidator::validate(bool useCurrentLine) {
    if(useCurrentLine) {
        string lineToValidate = ReadLine(_currentLine);

        // TODO: For now, we will return true on all lines and leave actual validity checks for
        //       Sprint 2.
    }

    return true;
}

string InterfaceValidator::ReadLine(int lineToRead) const {
    string >>
}
