#include "directory.h"

Directory::Directory(string directoryName){
    numFiles = 0;
    dir = directoryName;
    getFiles();
}

void Directory::printDirectory(){
    for (unsigned int i = 0;i < files.size();i++) {
        cout << files[i] << endl;
    }
}

int Directory::getFiles()
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (string(dirp->d_name) != "." && string(dirp->d_name) != ".." && string(dirp->d_name) != ".DS_Store"){
            files.push_back(string(dirp->d_name));
            numFiles++;
        }
    }
    closedir(dp);
    return 0;
}

