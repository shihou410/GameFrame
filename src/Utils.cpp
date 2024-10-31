#include "../include/Utils.h"
#include <cctype>
#include <sstream>
#include <string>

std::vector<std::string> Tools::string_splice(const std::string str,
                                              const char trim) {
  std::stringstream ss(str);
  std::string out;
  std::vector<std::string> array;
  while (std::getline(ss, out, trim)) {
    array.push_back(Tools::string_strim(out));
  }
  return array;
}

std::string Tools::string_strim(std::string str) {

  auto begin = str.begin();
  auto end = str.end() - 1;

  while (std::isspace(*begin) || std::isspace(*end)) {
    if (std::isspace(*begin)) {
      begin++;
    }
    if (std::isspace(*end)) {
      end--;
    }
  }
  return std::string(begin, end + 1);
}

int Tools::random(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);
  return dis(gen);
}
