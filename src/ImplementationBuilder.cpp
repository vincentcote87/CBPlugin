#include "ImplementationBuilder.h"

ImplementationBuilder::ImplementationBuilder() {}

bool operator==(const ImplementationBuilder& lhs, const ImplementationBuilder& rhs) {
    if(lhs._validator == rhs._validator)
        return true;

    return false;
}
