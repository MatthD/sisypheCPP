//
// Created by Matthias Dieudonne on 04/02/2018.
//

#ifndef SISYPHECPP_MAGIC_H
#define SISYPHECPP_MAGIC_H

#include <magic.h>
#include <string>
#include <cassert>

using namespace std;
class Magic {
  magic_t magic;
  public:
    Magic();
    explicit Magic(const char*);
    string detectMimetype(string);
    void destroyMagic();
};


#endif //SISYPHECPP_MAGIC_H
