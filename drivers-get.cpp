//finds unknown drivers from current pc and copies them to drives storage
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

// gets the array of data from lib.d
string get_lib(string cwd) {
  string line, library;
  int librarySize, libraryLength;
  librarySize = library.length();
  ifstream lib;
  // reads the lib.d file into a string
  lib.open("lib.d");
  if (lib.is_open()) {
    while (getline(lib,line)) {
      library += line;
    }
    lib.close();
  }
  else cout << "Could not open lib.d";
  // count the data values to determine length of library
  libraryLength = 0;
  int pos = library.find("/",0;);
  while (pos != string::npos){
    libraryLength++;
    pos = str.find("/",pos+1)
  }
  libraryLength = libraryLength / 4;
  // convert library text to array format

  }
  return library;
}

int main() {
  string cwd = filesystem::current_path();
  cout << "CWD: " << cwd << endl;
  string lib = get_lib(cwd);
  cout << lib << endl;
  return 0;
}
