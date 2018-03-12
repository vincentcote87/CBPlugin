#ifndef INTERFACEVALIDATOR_H
#define INTERFACEVALIDATOR_H

#include <istream>
#include <string>

using std::istream;
using std::string;

class InterfaceValidator {
    public:
        InterfaceValidator() {}
        inline explicit InterfaceValidator(istream* interface) { _interface = interface; }
        virtual ~InterfaceValidator() { delete _interface; }
        virtual string next() = 0;
        virtual inline void setInterface(istream* interface) { _interface = interface; }

    protected:
        istream* _interface;
        virtual bool validate(bool = true) const = 0;
};

#endif // INTERFACEVALIDATOR_H
