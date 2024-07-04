#include "parser.h"

Parser::Parser(string* tokens) {
    this->tokens = *tokens;
}

bool Parser::checkBrackets() {
    map<char, char> openToClosingBrackets;
    openToClosingBrackets['('] = ')';
    openToClosingBrackets['['] = ']';
    openToClosingBrackets['{'] = '}';

    std::cout << "Start to check parentheses" << endl;
    vector<char> brackets;
    for (int i = 0; i < tokens.size(); ++i) {
        char t = tokens[i];
        if (t == '}' || t == ')' || t == ']') {
            if (brackets.size() > 0) {
                char last = brackets.back();
                if (openToClosingBrackets[last] == t) {
                    brackets.pop_back();
                } else {
                    throw BracketsNotMatching();
                }
            } else {
                throw BracketsNotMatching();
            }
        } else if (t == '(' || t == '[' || t == '{') {
            brackets.push_back(t);
        }
    }
    if (brackets.size() > 0) {
        throw BracketsNotMatching();
    }
    return true;
}

bool Parser::parse() {
    return checkBrackets();
}
