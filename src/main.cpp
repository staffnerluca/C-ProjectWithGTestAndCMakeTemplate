#include "lexer.h"
#include "parser.h"

int main(int argc, char *argv[]){
    Lexer l = Lexer(argv[1]);
    vector<string> tokensl = l.lex();
    std::cout << argv[1];
    for (const auto& line : tokensl) {
        std::cout << line << std::endl;
    }

    string* tokens = tokensl.data();
    int size = tokensl.size();

    Parser parser(tokens);
    parser.parse();
    return 0;
}