#include "functions.h"
#include <iostream>
#include "chars.h"

#define array_size(A) (sizeof(A)/sizeof(A[0]))
#define check_loop(A) \
  for (size_t i = 0; i < array_size(A); i++) \
    if (A[i] == c) \
      return true;

bool is_floating_vowel (wchar_t c)
{
  check_loop(_floating_vowels);
  check_loop(_floating_vowels_left);
  return false;
}

bool is_backward_floating_vowel (wchar_t c)
{
  check_loop(_backward_floating_vowels);
  return false;
}

bool is_tone_marker (wchar_t c)
{
  check_loop(_tone_marker_high);
  check_loop(_tone_marker_left_low);
  check_loop(_tone_marker_low);
  check_loop(_tone_marker_left_high);
  return false;
}

bool is_long_tail (wchar_t c)
{
  check_loop(_long_tail);
  // include these as they're
  // acting for the above
  check_loop(_floating_vowels_left);
  check_loop(_tone_marker_left_low);
  check_loop(_tone_marker_left_high);
  return false;
}

bool is_lower_foot (wchar_t c)
{
  check_loop(_lower_foot);
  return false;
}

bool is_lower_vowel (wchar_t c)
{
  check_loop(_lower_vowels);
  return false;
}

bool is_lower_tail (wchar_t c)
{
  check_loop(_lower_tail);
  return false;
}

void log_fix (wchar_t a, wchar_t b)
{
  std::wcout << L'!' ;//<< std::showbase << std::hex << a << '>' << b;
}

wchar_t fix_floating_vowel (wchar_t c, const wchar_t *fix)
{
  for (size_t i = 0; i < array_size(_floating_vowels); i++) {
    if (_floating_vowels[i] == c) {
      log_fix(c, fix[i]);
      return fix[i];
    }
  }
  return c;
}

wchar_t fix_tone_marker (wchar_t c, const wchar_t *fix)
{
  for (size_t i = 0; i < array_size(_tone_marker_high); i++) {
    if (_tone_marker_high[i] == c) {
      log_fix(c, fix[i]);
      return fix[i];
    }
  }
  return c;
}

wchar_t fix_lower_foot (wchar_t c, const wchar_t *fix)
{
  for (size_t i = 0; i < array_size(_lower_foot); i++) {
    if (_lower_foot[i] == c) {
      log_fix(c, fix[i]);
      return fix[i];
    }
  }
  return c;
}

wchar_t fix_lower_vowel (wchar_t c, const wchar_t *fix)
{
  for (size_t i = 0; i < array_size(_lower_vowels); i++) {
    if (_lower_vowels[i] == c) {
      log_fix(c, fix[i]);
      return fix[i];
    }
  }
  return c;
}