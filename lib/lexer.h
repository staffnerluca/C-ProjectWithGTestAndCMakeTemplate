#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Lexer {
private:
    string path;

    vector<string> getTokens(vector<string>& lines);
    vector<string> getLineList(string filePath);

public:
    Lexer(string fPath);
    vector<string> lex();
};

#endif // LEXER_H
