//
// Created by Matthias Dieudonne on 06/02/2018.
//

#ifndef SISYPHECPP_OUT_H
#define SISYPHECPP_OUT_H

#include <string>
#include <json/writer.h>
#include <boost/filesystem.hpp>

using namespace std;
class Out {
  const string& outputPath;
  string defaultOutputPath = "output.json";
  ofstream fout;
  public:
    Out();
    explicit Out(const string& path);
    void toJsonFile(Json::Value);
};


#endif //SISYPHECPP_OUT_H
