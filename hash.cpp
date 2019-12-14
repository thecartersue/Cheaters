#include "hash.h"

Hash::Hash(int b){
    this->tableSize = b;
    table = new list<int>[tableSize];
}

void Hash::insertItem(string key, int fileNumber){
    int index = hashFunction(key);
    if (table[index].back() != fileNumber) {
        table[index].push_back(fileNumber);
    }
}

int Hash::hashFunction(string x) {
    int asciiSum = 0;
    for (int i = 0; i < 15; i++){
        asciiSum = asciiSum + (x[i]*pow(3, i));
    }
    return (asciiSum % tableSize);
}