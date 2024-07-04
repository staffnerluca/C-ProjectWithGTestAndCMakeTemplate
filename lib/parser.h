#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "custom_exceptions.h"

using namespace std;

class Parser {
private:
    string tokens;
    bool checkBrackets();

public:
    Parser(string* tokens);
    bool parse();
};

#endif // PARSER_H
