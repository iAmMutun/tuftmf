#include "functions.h"
#include "chars.h"

#define array_size(A) (sizeof(A)/sizeof(A[0]))
#define check_loop(A) \
  for (size_t i = 0; i < array_size(A); i++) \
    if (A[i] == c) \
      return true;

namespace tuftmf
{

bool is_double_quote (_Tchar c)
{
    return c == _double_quote;
}

bool is_argument (_Tchar c)
{
    return c == _at_sign;
}

bool is_digit (_Tchar c)
{
    check_loop(_digits);
    return false;
}

bool is_floating_vowel (_Tchar c)
{
    check_loop(_floating_vowels);
    check_loop(_floating_vowels_left);
    return false;
}

bool is_backward_floating_vowel (_Tchar c)
{
    check_loop(_backward_floating_vowels);
    return false;
}

bool is_tone_marker (_Tchar c)
{
    check_loop(_tone_marker_high);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_long_tail (_Tchar c)
{
    check_loop(_long_tail);
    // include these as they're
    // acting for the above
    check_loop(_floating_vowels_left);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_lower_foot (_Tchar c)
{
    check_loop(_lower_foot);
    return false;
}

bool is_lower_vowel (_Tchar c)
{
    check_loop(_lower_vowels);
    return false;
}

bool is_lower_tail (_Tchar c)
{
    check_loop(_lower_tail);
    return false;
}

_Tchar fix_floating_vowel (_Tchar c, const _Tchar *fix)
{
    for (size_t i = 0; i < array_size(_floating_vowels); i++) {
        if (_floating_vowels[i] == c) {
            return fix[i];
        }
    }
    return c;
}

_Tchar fix_tone_marker (_Tchar c, const _Tchar *fix)
{
    for (size_t i = 0; i < array_size(_tone_marker_high); i++) {
        if (_tone_marker_high[i] == c) {
            return fix[i];
        }
    }
    return c;
}

_Tchar fix_lower_foot (_Tchar c, const _Tchar *fix)
{
    for (size_t i = 0; i < array_size(_lower_foot); i++) {
        if (_lower_foot[i] == c) {
            return fix[i];
        }
    }
    return c;
}

_Tchar fix_lower_vowel (_Tchar c, const _Tchar *fix)
{
    for (size_t i = 0; i < array_size(_lower_vowels); i++) {
        if (_lower_vowels[i] == c) {
            return fix[i];
        }
    }
    return c;
}

_Tchar move_floating_left (_Tchar c)
{
    return fix_floating_vowel(c, _floating_vowels_left);
}

_Tchar move_tone_marker_low (_Tchar c)
{
    return fix_tone_marker(c, _tone_marker_low);
}

_Tchar move_tone_marker_left_height (_Tchar c)
{
    return fix_tone_marker(c, _tone_marker_left_high);
}

_Tchar move_tone_marker_left_low (_Tchar c)
{
    return fix_tone_marker(c, _tone_marker_left_low);
}

_Tchar strip_lower_foot (_Tchar c)
{
    return fix_lower_foot(c, _lower_foot_stripped);
}

_Tchar move_lower_vowel_left (_Tchar c)
{
    return fix_lower_vowel(c, _lower_vowels_left);
}

} // namespace tuftmf
