#include <fstream>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

using namespace std::filesystem;
using std::string, std::next, std::end;

int recursive(string path) {
  int count = 0;
  string output;
  int o = 0;
  for (auto & files: directory_iterator(path)) {
    if (o == 0) {
      o = 1;
      continue;
    }
    else if (files.is_regular_file()) {
      if (files.path().extension() == ".md" || files.path().extension() == ".txt") {
        std::ifstream myfile;
        myfile.open(files.path());
        if (myfile.is_open()) {
        string sfp="";
        while (getline(myfile, sfp)) { 
            output.append(sfp); 
        } 
          std::istringstream stream(output);
          string word;
          while (stream >> word) {
            count++;
          }
        }
        myfile.close();
      }
    } else if (files.is_directory()) {
      count = count + recursive((files.path()));
    }
  }
  return (count);
}

int main(int argc, char * argv[]) {
  string input = string(argv[1]);
  bool x = false;
  string output ="";
  int count = 0;
  int o = 0;
  for (auto & files: directory_iterator(input)) {
    if (o == 0) {
      o = 1;
      continue;
    }
    else if (files.is_regular_file()) {
      if (files.path().extension() == ".md" || files.path().extension() == ".txt") {
        std::ifstream myfile;
        myfile.open(files.path());
        if (myfile.is_open()) {
        string sfp="";
        while (getline(myfile, sfp)) { 
            output.append(sfp); 
        } 
          std::istringstream stream(output);
          string word;
          while (stream >> word) {
            count++;
          }
        }
        myfile.close();
      }
    } else if (files.is_directory()) {
      count = count + recursive((files.path()));
    }

  }
  std::cout << count;
  return (1);
}