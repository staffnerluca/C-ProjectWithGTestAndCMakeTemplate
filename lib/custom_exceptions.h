#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

#include <exception>

class BracketsNotMatching : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Brackets do not match!";
    }
};

#endif