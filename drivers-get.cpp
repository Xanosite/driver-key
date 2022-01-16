//finds unknown drivers from current pc and copies them to drives storage
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

// gets the array of data from lib.d
string get_lib_text(string cwd) {
  string line, libraryText;
  int librarySize, libraryLength;
  librarySize = libraryText.length();
  ifstream lib;
  // reads the lib.d file into a string
  lib.open("lib.d");
  if (lib.is_open()) {
    while (getline(lib,line)) {
      libraryText += line;
    }
    lib.close();
  }
  else cout << "Could not open lib.d";
  return libraryText;
}

// gets length of libraryText
int library_length(string libraryText) {
  // count the data values to determine length of library
  if (libraryText.length() == 0) {return 0;}
  int libraryLength = 0;
  int pos = libraryText.find("/",0);
  while (pos != string::npos){
    libraryLength++;
    pos = libraryText.find("/",pos+1);
  }
  libraryLength = libraryLength / 4;
  return libraryLength;
}

// converts text file library into array
int libText_to_arr(string library[][4], string libraryText) {
  int pos0, pos1, i, j;
  pos0 = libraryText.find("/",0);
  pos1 = libraryText.find("/",pos0+1);
  i = 0;
  j = 0;
  // divide string into array components
  while (pos1 != string::npos){
    library[i][j] = libraryText.substr(pos0+1, pos1-(pos0+1));
    pos0 = pos1;
    pos1 = libraryText.find("/",pos1+1);
    j++;
    // iterate i and reset j on fourth entry
    if (j == 4) {
      i++;
      j = 0;
    }
  }
  return 0;
}

// counts files/folders in directory
int drivers_count(string directory) {
  int i = 0;
  for (const auto & entry : filesystem::directory_iterator(directory)) {
    i++;
  }
  return i;
}

// prints out text at program start
int start_message(string cwd) {
  string line, msgLoc;
  msgLoc = cwd + "/dat/start.msg";
  ifstream msgFile;
  msgFile.open(msgLoc);
  if (!(msgFile.is_open())) {
    cout << "Error: Could not read start text file.";
    return 1;
  }
  while (getline(msgFile,line)) {
    cout << line << endl;
  }
  msgFile.close();
  cout << endl;
  return 0;
}

int main() {
  string cwd = filesystem::current_path();
  string driversDirectory = cwd + "/lib/";
  start_message(cwd);
  // get library array set up
  string libText = get_lib_text(cwd);
  int libSize = library_length(libText);
  string library[libSize][4];
  libText_to_arr(library, libText);
  // text for user
  cout << "Current drivers in library: " << libSize << endl;
  cout << "Searching directory: " << driversDirectory << endl;
  cout << "Found " << drivers_count(driversDirectory) << " drivers." << endl;
  return 0;
}
