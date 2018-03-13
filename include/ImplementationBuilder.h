#ifndef IMPLEMENTATIONBUILDER_H
#define IMPLEMENTATIONBUILDER_H

#include "InterfaceValidator.h"
#include <string>

using std::string;

class ImplementationBuilder {
    public:
        inline explicit ImplementationBuilder(InterfaceValidator* validator) : _validator{validator} {}
        virtual ~ImplementationBuilder() { delete _validator; }
        virtual int build(wxString) = 0;

    protected:
        InterfaceValidator* _validator;
};

#endif // IMPLEMENTATIONBUILDER_H
