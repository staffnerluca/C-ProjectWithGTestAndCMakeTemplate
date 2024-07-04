#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <openssl/sha.h>
#include <iomanip>

using namespace std;

string hashKeywordsFile(){
    ifstream file("keywords.csv", ifstream::binary);
    if (!file) {
        cerr << "Failed to open" << endl;
        return "Failed";
    }

    //contains internal data and buffers required for the computing of the hash
    SHA256_CTX sha256Context;
    SHA256_Init(&sha256Context);

    char buffer[8192]; // number is random
    while (file.read(buffer, sizeof(buffer))) {
        //file.gcount retunr the number of read characters
        SHA256_Update(&sha256Context, buffer, file.gcount());
    }
    file.close();

    //unsigned char = byte
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256Context);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        //output fills with 0 if it is shorter than 2 digits
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}


void saveHASHValueOfKeywords(){
    ofstream file("previousHash.txt", ofstream::trunc);
    if(!file.is_open()){
        cerr << "Something went wrong" << endl;
    }
    file << hashKeywordsFile();
    file.close();
}


bool didKeywordsChange(){
    //compare hash of old file to hash of new file
    ifstream file("hashKeywords.txt");
    if(!file){
        return true;
    }
    //second istreambuf_iterator needed to let it know to stop reading when reaching the end
    string oldHash((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    string newHash = hashKeywordsFile();
    if(oldHash == newHash){
       return false; 
    }
    return true;
}