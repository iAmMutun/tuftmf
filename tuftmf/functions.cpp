#include "functions.h"
#include "chars.h"

#define array_size(A) (sizeof(A)/sizeof(A[0]))
#define check_loop(A) \
  for (size_t i = 0; i < array_size(A); i++) \
    if (A[i] == c) \
      return true;

namespace tuftmf
{

bool is_double_quote (char_type c)
{
    return c == _double_quote;
}

bool is_digit (char_type c)
{
    check_loop(_digits);
    return false;
}

bool is_floating_vowel (char_type c)
{
    check_loop(_floating_vowels);
    check_loop(_floating_vowels_left);
    return false;
}

bool is_backward_floating_vowel (char_type c)
{
    check_loop(_backward_floating_vowels);
    return false;
}

bool is_tone_marker (char_type c)
{
    check_loop(_tone_marker_high);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_long_tail (char_type c)
{
    check_loop(_long_tail);
    // include these as they're
    // acting for the above
    check_loop(_floating_vowels_left);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_lower_foot (char_type c)
{
    check_loop(_lower_foot);
    return false;
}

bool is_lower_vowel (char_type c)
{
    check_loop(_lower_vowels);
    return false;
}

bool is_lower_tail (char_type c)
{
    check_loop(_lower_tail);
    return false;
}

char_type fix_floating_vowel (char_type c, const char_type *fix)
{
    for (size_t i = 0; i < array_size(_floating_vowels); i++) {
        if (_floating_vowels[i] == c) {
            return fix[i];
        }
    }
    return c;
}

char_type fix_tone_marker (char_type c, const char_type *fix)
{
    for (size_t i = 0; i < array_size(_tone_marker_high); i++) {
        if (_tone_marker_high[i] == c) {
            return fix[i];
        }
    }
    return c;
}

char_type fix_lower_foot (char_type c, const char_type *fix)
{
    for (size_t i = 0; i < array_size(_lower_foot); i++) {
        if (_lower_foot[i] == c) {
            return fix[i];
        }
    }
    return c;
}

char_type fix_lower_vowel (char_type c, const char_type *fix)
{
    for (size_t i = 0; i < array_size(_lower_vowels); i++) {
        if (_lower_vowels[i] == c) {
            return fix[i];
        }
    }
    return c;
}

char_type move_floating_left (char_type c)
{
    return fix_floating_vowel(c, _floating_vowels_left);
}

char_type move_tone_marker_low (char_type c)
{
    return fix_tone_marker(c, _tone_marker_low);
}

char_type move_tone_marker_left_height (char_type c)
{
    return fix_tone_marker(c, _tone_marker_left_high);
}

char_type move_tone_marker_left_low (char_type c)
{
    return fix_tone_marker(c, _tone_marker_left_low);
}

char_type strip_lower_foot (char_type c)
{
    return fix_lower_foot(c, _lower_foot_stripped);
}

char_type move_lower_vowel_left (char_type c)
{
    return fix_lower_vowel(c, _lower_vowels_left);
}

} // namespace tuftmf
