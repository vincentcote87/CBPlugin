#ifndef INTERFACEVALIDATOR_H
#define INTERFACEVALIDATOR_H

#include <istream>
#include <string>

using std::istream;
using std::string;

class InterfaceValidator {
    public:
        InterfaceValidator() {}
        InterfaceValidator(istream* is) { _interface = is; }
        virtual ~InterfaceValidator() { delete _interface; }
        virtual string next() = 0;
        virtual inline void setInterface(istream* interface) { _interface = interface; }
        virtual inline void setInterface(istream& interface) { _interface = &interface; }
        virtual void setInterface(const string&) = 0;
        inline const istream& getInterface() const { return *(_interface); }

        friend bool operator==(const InterfaceValidator&, const InterfaceValidator&);
        InterfaceValidator& operator=(const InterfaceValidator&);
    protected:
        istream* _interface;
        virtual bool validate(bool = true) const = 0;
};

#endif // INTERFACEVALIDATOR_H
