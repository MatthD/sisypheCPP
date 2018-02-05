/*
 * This is a CPP version of the sisyphe aim
 * */
#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <json/writer.h>

#include "Magic.h"

namespace fs = boost::filesystem;
using namespace std;

int main(int nbOfArgs, char *args[]) {
  Magic magicInstance{};
  const fs::path p = args[1];
  ofstream fout("output.json");
  for (const auto& currPath : fs::recursive_directory_iterator(p)){
    Json::Value file;
    string pathStr = currPath.path().string();
    if(fs::is_regular_file(pathStr)){
      file["path"] = pathStr;
      file["mimetype"] = magicInstance.detectMimetype(pathStr);
      fout << file << endl;
    }
  }
  magicInstance.destroyMagic();
}