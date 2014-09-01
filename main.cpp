#include <fstream>
#include <iostream>
#include <locale>
#include <regex>

void scan_dir(const std::wstring& in, const std::wstring& out);

std::wstring backslash(const std::wstring& s) {
  static const std::wregex e(L"/");
  static const std::wstring bs = L"\\";
  return std::regex_replace(s, e, bs);
}

int wmain(int argc, wchar_t** argv)
{
  argc--;
  argv++;

  if (argc < 1) {
    std::wcerr << L"Must have atleast 1 argument";
    return -1;
  } else if (argc == 1) {
    std::wstring in = backslash(argv[0]);
    scan_dir(in, L".\\");
  } else {
    std::wstring out = backslash(argv[argc - 1]);
    for (int i = 0; i < argc - 1; i++) {
      std::wstring in = backslash(argv[i]);
      scan_dir(in, out);
    }
  }
  return 0;
}
