#ifndef UNGUELTIGES_DATUM_EXCEPTION_H
#define UNGUELTIGES_DATUM_EXCEPTION_H

#include <stdexcept>
#include <string>

class UngueltigesDatumException: public std::runtime_error {

    public:
        UngueltigesDatumException(std::string message) : std::runtime_error(message) {}

};

#endif