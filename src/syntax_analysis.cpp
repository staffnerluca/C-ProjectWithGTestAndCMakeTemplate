#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <regex>
#include "syntax_analysis.h"
#include "custom_exceptions.h"

using namespace std;


map<string, vector<string>*>* keywords;


vector<string> getSynonyms(string word){
    vector<string> synonyms;
    synonyms.push_back(word);
    return synonyms;
}


bool isNumber(string tok){
    if(!isdigit(tok[0])){
        return false;
    }
    for(char t : tok){
        if(!isdigit(t) && t != '.'){
            return false;
        }
    }
    return true;
}


bool isKeyword(string word){
    return false;
    try{
        keywords->operator[](word);
        return true;
    }catch(exception ex){
        /*if(getParentOfSynonym(word, keywords) != "nf"){
            return true;
        }*/
        return false;
    }
}


bool isValidVar(string var){
    if(isKeyword(var)){
        return false;
    }
    if(isdigit(var[0])){
        return false;
    }
    for(char c : var){
        if(!isdigit(c) && !isalpha(c) && c != '_' && c != '-'){
            return false;
        }
    }
    return true;
}


bool isOperator(string tok){
    vector<string> operators{"+", "-", "*", "/"};
    for(string op : operators){
        if(tok == op){
            return true;
        }
    }
    return false;
}


bool checkExpression(vector<string> tokens){
    if(isOperator(tokens[0])){
        return false;
    }
    bool containsOperator = false;
    for(int t = 0; t < tokens.size(); t++){
        if(isOperator(tokens[t])){
            //prevents that two operators are next to each other
            if(isOperator(tokens[t+1])){
                return false;
            }
            containsOperator = true;
        }
        else if(!isNumber(tokens[t]) && !isValidVar(tokens[t]) && tokens[t] != "(" && tokens[t] != ")"){
            return false;
        }
    }
    if(!containsOperator){
        return false;
    }

    return true;
}


vector<int> getExpressionPosition(vector<string>* t){
    //get where an expression starts
    vector<int> pos{0, 0};
    return pos;
}


bool isString(string var){
    return false;
}


bool isInt(string var){
    regex intPattern("^-?\\d+$");
    return regex_match(var, intPattern);
}


bool isBool(string var){
    //get synonyms for true and false
    /*string value = getParentOfSynonym(var, keywords);
    if(value == "true" || value == "false"){
        return true;
    }*/
    return false;
}


bool isValue(string var){
    return false;
}


bool checkBrackets(vector<string>* tokensP){
    map<char, char> openToClosingBrackets;
    openToClosingBrackets['('] = ')';
    openToClosingBrackets['['] = ']';
    openToClosingBrackets['{'] = '}';
    vector<string> tokens = *tokensP;
    std::cout << "Start to check par" << endl;
    vector<char> brackets;
    for(int i = 0; i < tokens.size(); ++i){
        string to = tokens[i];
        if(to.size() == 1){
            char t = to[0];
            if (t == '}' || t == ')' || t == ']') {
                if(brackets.size() > 0){
                    char last = brackets.back();
                    if (openToClosingBrackets[last] == t){
                        brackets.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else if(t == '(' || t == '[' || t == '{'){
                brackets.push_back(t);
            }
        }   
    }
    if(brackets.size() > 0){
        return false;
    }
    return true;
}


bool checkFor(vector<string>* tokens){
    return false;
}


bool checkWhile(vector<string>* tokens){
    return false;
}


//tokens contains only the tokens from the beginning of the if until the first { because we know the brackets are correct
bool checkIf(vector<string>* t){
    vector<string> tokens = *t;
    int placeOfFirstVarOrValue = 2;
    if(tokens[1] != "("){
        placeOfFirstVarOrValue -= 1;
    }
    string firstRelevantToken = tokens[placeOfFirstVarOrValue];
    if(!isValidVar(firstRelevantToken) || !isValue(firstRelevantToken)){
        return false;
    }

    if(getExpressionPosition(t) != vector<int>{0, 0}){
        cout << "hurray a expression";
    }
    return true;
}


bool checkFunction(vector<string>* tokens){
    return false;
}


bool checkVarDeclaration(){
    return false;
}


// need to give a vector<string> to it
bool checkSyntax(vector<string>* tokens){
    //keywords = getKeywords();

    if(!checkBrackets(tokens)){
        throw BracketsNotMatching();
        return false;
    }
    return true;
}

//in Test file auslagern
void testIsVarValid(){
    vector<string> casesIsValidVarTrue{"test"};
    vector<string> casesIsValidVarFalse{"te(st", "1Test"};
    for(string cas : casesIsValidVarTrue){
        if(!isValidVar(cas)){
            cout << "Failed isValidVar at case "+cas+". Should be true";
        }
    }
    for(string cas : casesIsValidVarFalse){
        if(isValidVar(cas)){
            cout << "Failed isValidVar at case "+cas+". Should be false" << endl;
        }
    }
}

void testCheckExpression(){
    vector<vector<string>> checkExpressionTrue;
    checkExpressionTrue.push_back(vector<string>{"1", "+", "2"});
    checkExpressionTrue.push_back(vector<string>{"1", "+","2", "*", "1"});
    checkExpressionTrue.push_back(vector<string>{"1", "+","2", "*", "(", "-", "1", ")"});

    vector<vector<string>> checkExpressionFalse;
    checkExpressionFalse.push_back(vector<string>{"1", "+", "-","2"});
    checkExpressionFalse.push_back(vector<string>{"*", "1", "-","2"});
    checkExpressionFalse.push_back(vector<string>{"11", "2"});


    for(vector<string> exp : checkExpressionTrue){
        if(!checkExpression(exp)){
            string expAsString;
            for(string st  : exp){
                expAsString+=st;
            }
            cout << "Failed testCheckExpression at case " << expAsString << ". Should be true." << endl;
        }
    }

    for(vector<string> exp : checkExpressionFalse){
        if(checkExpression(exp)){
            string expAsString;
            for(string st  : exp){
                expAsString+=st;
            }
            cout << "Failed testCheckExpression at case " << expAsString << ". Should be false" << endl;
        }
    }
}


int main(){
    cout << "this is great" << endl;

    testIsVarValid();
    testCheckExpression();
    return 0;
}