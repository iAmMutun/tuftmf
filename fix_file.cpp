#include <iostream>
#include <locale>
#include "functions.h"
#include "rsc.hpp"

void fix_file(const std::wstring& in, const std::wstring& out)
{
  std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
  rsc::istream fsin (in);
  rsc::ostream fsout(out);

  int count = 0;
  bool quote = false;
  char16_t before = L'\0';
  char16_t current, after;
  fsin.get(current);
  while (!fsin.eof())
  {
    fsin.get(after);
    
    if (is_double_quote(current))
      quote = !quote;

    if (!quote)
    {
      // not in quote, do nothing
    }
    else if (is_argument(current))
    {
      count++;
      fsout.put(argument_prefix());
    }
    else if (is_floating_vowel(current))
    {
      if (is_long_tail(before)) {
        count++;
        current = move_floating_left(current);
      }
    }
    else if (is_floating_vowel(current))
    {
      if (is_long_tail(before)) {
        count++;
        current = move_floating_left(current);
      }
    }
    else if (is_tone_marker(current))
    {
      if (is_floating_vowel(before)) {
        if (is_long_tail(before)) {
          count++;
          current = move_tone_marker_left_height(current);
        }
      } else if (is_long_tail(before)){
        if (is_backward_floating_vowel(after)) {
          count++;
          current = move_tone_marker_left_height(current);
        } else {
          count++;
          current = move_tone_marker_left_low(current);
        }
      } else if (!is_backward_floating_vowel(after)) {
        count++;
        current = move_tone_marker_low(current);
      }
    }
    else if (is_lower_foot(current))
    {
      if (is_lower_vowel(after)) {
        count++;
        current = strip_lower_foot(current);
      }
    }
    else if (is_lower_vowel(current))
    {
      if (is_lower_tail(before)) {
        count++;
        current = move_lower_vowel_left(current);
      }
    }

    fsout.put(current);
    before = current;
    current = after;
  } // while

  if (count > 0)
    std::wcout << L'\n';
  std::wcout << L"fixed:" << count << std::endl;
}
