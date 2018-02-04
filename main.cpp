/*
 * This is a CPP version of the sisyphe aim
 * */
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>

#include "Magic.h"


namespace fs = boost::filesystem;
using namespace std;

int main(int nbOfArgs, char *args[]) {
  Magic magicInstance{};
  const fs::path p = args[1];
  for (const auto& currPath : fs::recursive_directory_iterator(p)){
    string pathStr = currPath.path().string();
    if(fs::is_regular_file(pathStr)){
      cout << currPath << " : " << magicInstance.detectMimetype(pathStr) << endl;
    }
  }
  magicInstance.destroyMagic();
}