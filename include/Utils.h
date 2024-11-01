#pragma once
#include <map>
#include <random>
#include <string>
#include <vector>

class Tools {
private:
  Tools();

  std::map<std::string, std::string> config;
  std::vector<int> array;

public:
  /** 字符串分割 */
  static std::vector<std::string> string_splice(const std::string str,
                                                const char trim);

  /** 去除字符串首尾的空格 */
  static std::string string_strim(std::string str);

  static int random(int, int);
};