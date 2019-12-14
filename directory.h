#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Directory{

public:
    string dir;
    vector<string> files;
    int numFiles;
    Directory(string directoryName);
    void printDirectory();
private:
    int getFiles();
};