#pragma once
#include <random>
#include <string>
#include <vector>

namespace Tools {

/** 字符串分割 */
std::vector<std::string> string_splice(const std::string str, const char trim);

/** 去除字符串首尾的空格 */
std::string string_strim(std::string str);

int random(int, int);

} // namespace Tools
