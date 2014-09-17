#include <fstream>
#include <iostream>
#include <locale>

void scan_dir(const std::wstring& in, const std::wstring& out);

int wmain(int argc, wchar_t** argv)
{
  argc--;
  argv++;

  if (argc < 1) {
    std::wcerr << L"Must have atleast 1 argument";
    return -1;
  } else if (argc == 1) {
    std::wstring in = argv[0];
    scan_dir(in, L".");
  } else {
    std::wstring out = argv[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
      std::wstring in = argv[i];
      scan_dir(in, out);
    }
  }
  return 0;
}
