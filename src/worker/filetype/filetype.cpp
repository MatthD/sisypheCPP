//
// Created by Matthias D 04/02/2018.
//

#include "filetype.h"

// Default constructor
Filetype::Filetype() {
  assert( (magic = magic_open(MAGIC_MIME_TYPE)) != nullptr );
  assert( magic_load(magic, "magic/magic.mgc" ) == 0 );
}

// Constructor with path to Magic database
Filetype::Filetype(const char* magicSentPath) {
  const char* magicDbPath = magicSentPath ? magicSentPath : "magic/magic.mgc" ;
  assert( (magic = magic_open(MAGIC_MIME_TYPE)) != nullptr );
  assert( magic_load(magic, magicDbPath ) == 0 );
  assert( magic_compile(magic, nullptr ) == 0 );
}

string Filetype::detectMimetype(string filename) {
  char const* mime;
  assert( (mime = magic_file(magic, filename.c_str())) != nullptr );
  string detected {mime};
  return detected;
}

void Filetype::destroyMagic() {
  magic_close(magic);
}
