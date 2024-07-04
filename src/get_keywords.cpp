#include "get_keywords.h"

string getParentOfSynonym(string synonym, map<string, vector<string>*>* keywords){
    for(string key : getKeys(keywords)){
        vector<string> synonyms = *keywords->operator[](key);
        for(string word : synonyms){
            if(word == synonym){
                return key;
            }
        }
    }
    return "nf";
}


vector<string> getKeys(map<string, vector<string>*>* keywords) {
    vector<string> keys;
    for (const auto& pair : *keywords) {
        keys.push_back(pair.first);
    }
    return keys;
}


map<string, vector<string>*>* getKeywords()
{   
    cout << "test";
    map<string, vector<string>*>* keywords;
    ifstream reader("keywords.csv");
    if(!reader.is_open()){
        cerr << "File keywords not found" << endl;
    }
    string line;
    bool first = true;
    vector<string> baseKeywords;

    while(getline(reader, line)){
        if(first){
            stringstream sst(line);
            string tok;
            while(getline(sst, tok, ';')){
                baseKeywords.push_back(tok);
            }
            for(string baseKeyword : baseKeywords){
                keywords->operator[](baseKeyword) = new vector<string>;
                //dic[]
            }
            first = false;
        }
        else{
            vector<string> keys;
            //get a list of the keys               
            for(const auto& pair : *keywords){
                keys.push_back(pair.first);
            }
            stringstream sst(line);
            string tok;
            vector<string> tokens;
            while(getline(sst, tok, ';')){
                tokens.push_back(tok);
            }
            for(int i = 0; i < tokens.size(); i++){
                //* are needed to influence the value of the vector
                (*(*keywords)[keys[i]]).push_back(tokens[i]);
            }
        }
    }
    return keywords;
}
