//
// Created by Matthias Dieudonne on 06/02/2018.
//

#include "out.h"

Out::Out() : outputPath(defaultOutputPath) {
  //ofstream fout(outputPath);
};
Out::Out(const string& path) : outputPath(path) {
  //ofstream fout(outputPath);
}

void Out::toJsonFile(Json::Value file) {
  //fout << file << endl;
};