/*
 * This is a CPP version of the sisyphe aim
 * */
#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <json/reader.h>
#include <json/writer.h>

#include "src/worker/filetype/filetype.h"

namespace fs = boost::filesystem;
using namespace std;

int main(int nbOfArgs, char *args[]) {
  // Load the workers list & parse it to json
  Json::Value workerList;
  ifstream file("worker.json");
  file >> workerList;
  Json::Value workers = workerList.get("workers", "none" );
  if(workers != "none"){
    for(const auto& worker : workers){
      cout << worker;
    }

//  Filetype filetype{};
//  const fs::path p = args[1];
//  ofstream fout("output.json");
//  for (const auto& currPath : fs::recursive_directory_iterator(p)){
//    Json::Value file;
//    string pathStr = currPath.path().string();
//    if(fs::is_regular_file(pathStr)){
//      file["path"] = pathStr;
//      file["mimetype"] = filetype.detectMimetype(pathStr);
//      fout << file << endl;
//    }
//  }
//  filetype.destroyMagic();
  return 0;
}