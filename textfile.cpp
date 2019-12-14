#include "textfile.h"



TextFile::TextFile(string path, int n){
    fillDeque(path);
    makeKeyDeque(n);
}


void TextFile::fillDeque(string path) {
    string word;
    word.clear();
    ifstream file;
    file.open(path.c_str());
    if (!file.is_open()) {
        cout << "error";
        return;
    }

    string fileAsString;
    fileAsString.clear();
    char x;
    while (!file.eof()) {
        x = file.get();
        if (x >= 'A' && x <= 'Z'){
            x = x + 32;
        }
        if ((x >= 'a' && x <= 'z') || x == ' '){
            fileAsString = fileAsString + x;
        }
    }


    int i = 0;
    while (i < fileAsString.length()) {
        while (fileAsString[i] != ' ') {
            word = word + fileAsString[i];
            i++;
        }
        if(!word.empty()){
            fileDeque.push_back(word);
        }
        word.clear();
        i++;
    }
}

void TextFile::makeKeyDeque(int n) {
    string word;
    word.clear();
    int beginning = 0;
    int ending = n;
    while (ending != fileDeque.size()) {
        for (int i = beginning; i < ending; i++) {
            word = word + fileDeque[i];
        }
        keyDeque.push_back(word);
        word.clear();
        beginning++;
        ending++;
    }
}
