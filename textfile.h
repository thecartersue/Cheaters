#include <fstream>
#include <deque>
#include "directory.h"
using namespace std;
class TextFile{
public:
    deque<string> keyDeque;
    TextFile(string path, int n);

private:
    deque<string> fileDeque;
    void openFileLinux(string path);
    string getCharacters();
    void fillDeque(string path);
    void makeKeyDeque(int n);
};