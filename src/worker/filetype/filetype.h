//
// Created by Matthias Dieudonne on 04/02/2018.
//

#ifndef SISYPHECPP_MAGIC_H
#define SISYPHECPP_MAGIC_H

#include <magic.h>
#include <string>
#include <cassert>

using namespace std;
class Filetype {
  magic_t magic;
  public:
    Filetype();
    explicit Filetype(const char*);
    string detectMimetype(string);
    void destroyMagic();
};


#endif //SISYPHECPP_MAGIC_H
