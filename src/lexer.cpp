#include "lexer.h"

Lexer::Lexer(string fPath) {
    path = fPath;
}

vector<string> Lexer::getTokens(vector<string>& lines) {
    vector<string> tokens;
    for (const string& l : lines) {
        istringstream st(l);
        string word;

        while (st >> word) {
            string token = "";
            for (char c : word) {
                if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';') {
                    if (!token.empty()) {
                        tokens.push_back(token);
                        token = "";
                    }
                    tokens.push_back(string(1, c));
                } else {
                    token += c;
                }
            }
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        tokens.push_back("\n");
    }
    return tokens;
}

vector<string> Lexer::getLineList(string filePath) {
    ifstream file(filePath);
    vector<string> list;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
    return list;
}

vector<string> Lexer::lex() {
    vector<string> lines = getLineList(path);
    vector<string> tokens = getTokens(lines);
    return tokens;
}
