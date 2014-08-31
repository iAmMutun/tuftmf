#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <windows.h>
#include "chars.h"
#include "functions.hpp"

void fix_file(const std::wstring& in, const std::wstring& out);

int wmain(int argc, wchar_t** argv)
{
  for (int i = 1; i < argc; i++)
  {
    std::wstring dir = argv[i];
    if (dir.back() != L'/' && dir.back() != L'\\')
      dir += L'\\';
    std::wstring filter = dir + L"TH_*.rsc";
    
    WIN32_FIND_DATAW ffd;
    HANDLE hFind;
    hFind = FindFirstFileW(filter.c_str(), &ffd);
    if (INVALID_HANDLE_VALUE == hFind)
      continue;
    
    std::wcout << L"dir:" << dir << L'\n';
    do
    {
      if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        continue;
      std::wstring in = ffd.cFileName;
      std::wstring out = in.substr(3);
      fix_file(dir + in, dir + out);
    }
    while(FindNextFileW(hFind, &ffd));

    FindClose(hFind);
  }
  return 0;
}

void fix_file(const std::wstring& in, const std::wstring& out)
{
  std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
  std::wifstream fsin(in, std::ios::binary);
  std::wofstream fsout(out, std::ios::binary);

  auto *facet = new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>; 
  auto locale = std::locale(fsin.getloc(), facet);
  fsin.imbue(locale);
  fsout.imbue(locale);
  fsout.put(0xFFFE);
 
  int count = 0;
  wchar_t before, current, after;
  before = 0;
  fsin.get(current);
  while (!fsin.eof())
  {
    fsin.get(after);
    if (is_floating_vowel(current))
    {
      if (is_long_tail(before)) {
        count++;
        current = fix_floating_vowel(current, _floating_vowels_left);
      }
    }
    else if (is_tone_marker(current))
    {
      if (is_floating_vowel(before)) {
        if (is_long_tail(before)) {
          count++;
          current = fix_tone_marker(current, _tone_marker_left_high);
        }
      } else if (is_long_tail(before)){
        if (is_backward_floating_vowel(after)) {
          count++;
          current = fix_tone_marker(current, _tone_marker_left_high);
        } else {
          count++;
          current = fix_tone_marker(current, _tone_marker_left_low);
        }
      } else if (!is_backward_floating_vowel(after)) {
        count++;
        current = fix_tone_marker(current, _tone_marker_low);
      }
    }
    else if (is_lower_foot(current))
    {
      if (is_lower_vowel(after)) {
        count++;
        current = fix_lower_foot(current, _lower_foot_stripped);
      }
    }
    else if (is_lower_vowel(current))
    {
      if (is_lower_tail(before)) {
        count++;
        current = fix_lower_vowel(current, _lower_vowels_left);
      }
    }

    fsout.put(current);
    before = current;
    current = after;
  };

  if (count)
    std::wcout << L'\n';
  std::wcout << L"fixed:" << count << L'\n';
}
