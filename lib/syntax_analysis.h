#ifndef SYNTAX_ANALYSIS_H
#define SYNTAX_ANALYSIS_H

#include <string>
#include <vector>
#include <map>

using namespace std;

extern map<string, vector<string>*>* keywords;

bool isNumber(string tok);
bool isKeyword(string word);
bool isValidVar(string var);
bool isOperator(string tok);
bool checkExpression(vector<string> tokens);
vector<int> getExpressionPosition(vector<string>* t);
bool isString(string var);
bool isInt(string var);
bool isBool(string var);
bool isValue(string var);
bool checkBrackets(vector<string>* tokensP);
bool checkFor(vector<string>* tokens);
bool checkWhile(vector<string>* tokens);
bool checkIf(vector<string>* t);
bool checkFunction(vector<string>* tokens);
bool checkVarDeclaration();
bool checkSyntax(vector<string>* tokens);

void testIsVarValid();
void testCheckExpression();

#endif // SYNTAX_ANALYSIS_H
