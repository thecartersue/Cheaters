#include <list>
#include <math.h>
#include "textfile.h"
using namespace std;
class Hash
{
public:
    int tableSize;
    list<int> *table;
    Hash(int b);
    void insertItem(string key, int fileNumber);
    int hashFunction(string x);
};
