#include <fstream>
#include <iostream>
#include <locale>
#include <windows.h>
#include "slash.hpp"

void fix_file(const std::wstring& in, const std::wstring& out);

void scan_dir(const std::wstring& in_dir, const std::wstring& out_dir)
{
  std::wstring in  = slash(in_dir);
  std::wstring out = slash(out_dir);
  CreateDirectoryW(out_dir.c_str(), NULL);
  
  std::wcout << L"dir:" << in << L'\n';
  std::wstring filter = in + L'*';

  WIN32_FIND_DATAW ffd;
  HANDLE hFind;
  hFind = FindFirstFileW(filter.c_str(), &ffd);
  if (hFind == INVALID_HANDLE_VALUE)
    return;
  do {
    if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      std::wstring dir = ffd.cFileName;
      if (dir != L"." && dir != L"..") {
        scan_dir(in + dir, out + dir);
      }
    } else {
      std::wstring file = ffd.cFileName;
      if (file.substr(file.length() - 4) == L".rsc")
        fix_file(in + file, out + file);
    }
  }
  while(FindNextFileW(hFind, &ffd));
  FindClose(hFind);
}