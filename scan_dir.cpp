#include <fstream>
#include <iostream>
#include <locale>
#include <windows.h>

void fix_file(const std::wstring& in, const std::wstring& out);

void scan_dir(const std::wstring& a, const std::wstring& b)
{
  std::wstring in = a;
  std::wstring out = b;
  if (in.back() != L'\\')
    in += L'\\';  
  if (out.back() != L'\\')
    out += L'\\';
  
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
        std::wstring out_dir = out + dir;
        CreateDirectoryW(out_dir.c_str(), NULL);
        scan_dir(in + dir, out_dir);
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