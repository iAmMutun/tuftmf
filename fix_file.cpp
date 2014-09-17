#include <iostream>
#include <locale>
#include "chars.h"
#include "functions.hpp"
#include "rsc.hpp"

void fix_file(const std::wstring& in, const std::wstring& out)
{
  std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
  rsc::istream fsin (in);
  rsc::ostream fsout(out);

  int count = 0;
  char16_t before = L'\0';
  char16_t current, after;
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
  } // while

  if (count > 0)
    std::wcout << L'\n';
  std::wcout << L"fixed:" << count << L'\n';
}
