#pragma once
#include <regex>

std::wstring slash(std::wstring str) {
#ifdef _WIN32
  static const std::wstring native_slash = L"\\";
  static const std::wstring foreigne_slash = L"/";
#else
  static const std::wstring native_slash = L"/";
  static const std::wstring foreigne_slash = L"\\";
#endif
  static const std::wregex regex(foreigne_slash);
  str = std::regex_replace(str, regex, native_slash);
  auto pos = str.length() - native_slash.length();
  std::wstring b = str.substr(pos);
  if (b != native_slash)
    str += native_slash;
  return str;
}