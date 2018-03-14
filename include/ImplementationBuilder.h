#ifndef IMPLEMENTATIONBUILDER_H
#define IMPLEMENTATIONBUILDER_H

#include "InterfaceValidator.h"
#include <string>

using std::string;

class ImplementationBuilder {
    public:
        ImplementationBuilder();
        ImplementationBuilder(InterfaceValidator* validator) : _validator{validator} {}
        virtual ~ImplementationBuilder() { delete _validator; }
        virtual string build(string) = 0;
        inline virtual const InterfaceValidator& getValidator() const { return *(_validator); }

        friend bool operator==(const ImplementationBuilder&, const ImplementationBuilder&);
    protected:
        InterfaceValidator* _validator;
};

#endif // IMPLEMENTATIONBUILDER_H
