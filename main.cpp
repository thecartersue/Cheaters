#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "hash.h"
using namespace std;

struct collisionOutput{
    int numCollisions;
    string fileA;
    string fileB;
};


void sortCollisions(vector<collisionOutput> &collisions){
    vector<collisionOutput> sortedCollisions;
    vector<collisionOutput> temp = collisions;
    while(!temp.empty()) {
        int minIndex = 0;
        collisionOutput min = temp[0];
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].numCollisions > min.numCollisions) {
                min = temp[i];
                minIndex = i;
            }
        }
        sortedCollisions.push_back(min);
        temp.erase(temp.begin() + minIndex);
    }
    collisions = sortedCollisions;
}

int main(int argc, char *argv[])
{
    string path = argv[1];
    int n = atoi(argv[2]);
    int threshold = atoi(argv[3]);
    //string path = "sm_doc_set";
    //int n = 6;
    //int threshold = 200;

    int tableSize = 999991;
    Directory directoryA(path);
    Hash h(tableSize);
    int arrayMax = directoryA.numFiles + 1;
    int collisionArray[arrayMax][arrayMax];

    for (int i = 0; i < arrayMax; i++){
        for (int j = 0; j < arrayMax; j++){
            collisionArray[i][j] = 0;
        }
    }
    vector<TextFile> directoryFiles;
    for (int i = 0; i < directoryA.numFiles; i++){
        directoryFiles.push_back(TextFile(directoryA.dir + "/" + directoryA.files[i], n));
    }

    for (int i = 0; i < directoryFiles.size(); i++) {
        int numKeys = directoryFiles[i].keyDeque.size();
        for (int j = 0; j < numKeys; j++){
            h.insertItem(directoryFiles[i].keyDeque[j], i+1);
        }
    }

    for (int i = 0; i<tableSize; i++) {
        while (!h.table[i].empty()) {
            for (list<int>::iterator it = h.table[i].begin(); it != h.table[i].end(); ++it) {
            collisionArray[h.table[i].front()][*it]++;
            }
            h.table[i].pop_front();
        }
    }
    vector<collisionOutput> collisions;

    for (int i = 0; i < arrayMax; i++){
        for (int j = 0; j < arrayMax; j++){
            if (i != j){
                if (collisionArray[i][j] > threshold){
                    //cout << collisionArray[i][j] << ": " << directoryA.files[i-1] << ", " << directoryA.files[j-1] << endl;
                    collisionOutput temp;
                    temp.numCollisions = collisionArray[i][j];
                    temp.fileB = directoryA.files[i-1];
                    temp.fileA = directoryA.files[j-1];
                    collisions.push_back(temp);
                }
            }
        }
    }

    sortCollisions(collisions);

    for (int i = 0; i<collisions.size(); i++) {
        cout << collisions[i].numCollisions << ": " << collisions[i].fileA << ", " << collisions[i].fileB << endl;
    }


    return 0;
}