#ifndef GET_KEYWORDS_H
#define GET_KEYWORDS_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

string getParentOfSynonym(string synonym, map<string, vector<string>*>* keywords);
vector<string> getKeys(map<string, vector<string>*>* keywords);
map<string, vector<string>*>* getKeywords();
void test();

#endif // GET_KEYWORDS_H
