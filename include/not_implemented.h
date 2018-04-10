#ifndef NOT_IMPLEMENTED_H
#define NOT_IMPLEMENTED_H

#include <stdexcept>

class not_implemented : public std::exception {
    public:
        const char * what () const throw () {
            return "Not Implemented Yet";
        }
};

#endif
