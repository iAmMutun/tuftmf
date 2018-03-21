#include "functions.h"
#include <iostream>
#include "chars.h"

#define array_size(A) (sizeof(A)/sizeof(A[0]))
#define check_loop(A) \
  for (size_t i = 0; i < array_size(A); i++) \
    if (A[i] == c) \
      return true;

namespace tuftmf
{

bool is_double_quote (uint16_t c)
{
    return c == _double_quote;
}

bool is_argument (uint16_t c)
{
    return c == _at_sign;
}

bool is_digit (uint16_t c)
{
    check_loop(_digits);
    return false;
}

bool is_floating_vowel (uint16_t c)
{
    check_loop(_floating_vowels);
    check_loop(_floating_vowels_left);
    return false;
}

bool is_backward_floating_vowel (uint16_t c)
{
    check_loop(_backward_floating_vowels);
    return false;
}

bool is_tone_marker (uint16_t c)
{
    check_loop(_tone_marker_high);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_long_tail (uint16_t c)
{
    check_loop(_long_tail);
    // include these as they're
    // acting for the above
    check_loop(_floating_vowels_left);
    check_loop(_tone_marker_left_low);
    check_loop(_tone_marker_left_high);
    return false;
}

bool is_lower_foot (uint16_t c)
{
    check_loop(_lower_foot);
    return false;
}

bool is_lower_vowel (uint16_t c)
{
    check_loop(_lower_vowels);
    return false;
}

bool is_lower_tail (uint16_t c)
{
    check_loop(_lower_tail);
    return false;
}

void log_fix (uint16_t a, uint16_t b)
{
    std::wcout << L'!';//<< std::showbase << std::hex << a << '>' << b;
}

uint16_t fix_floating_vowel (uint16_t c, const uint16_t *fix)
{
    for (size_t i = 0; i < array_size(_floating_vowels); i++) {
        if (_floating_vowels[i] == c) {
            log_fix(c, fix[i]);
            return fix[i];
        }
    }
    return c;
}

uint16_t fix_tone_marker (uint16_t c, const uint16_t *fix)
{
    for (size_t i = 0; i < array_size(_tone_marker_high); i++) {
        if (_tone_marker_high[i] == c) {
            log_fix(c, fix[i]);
            return fix[i];
        }
    }
    return c;
}

uint16_t fix_lower_foot (uint16_t c, const uint16_t *fix)
{
    for (size_t i = 0; i < array_size(_lower_foot); i++) {
        if (_lower_foot[i] == c) {
            log_fix(c, fix[i]);
            return fix[i];
        }
    }
    return c;
}

uint16_t fix_lower_vowel (uint16_t c, const uint16_t *fix)
{
    for (size_t i = 0; i < array_size(_lower_vowels); i++) {
        if (_lower_vowels[i] == c) {
            log_fix(c, fix[i]);
            return fix[i];
        }
    }
    return c;
}

uint16_t move_floating_left (uint16_t c)
{
    return fix_floating_vowel(c, _floating_vowels_left);
}

uint16_t move_tone_marker_low (uint16_t c)
{
    return fix_tone_marker(c, _tone_marker_low);
}

uint16_t move_tone_marker_left_height (uint16_t c)
{
    return fix_tone_marker(c, _tone_marker_left_high);
}

uint16_t move_tone_marker_left_low (uint16_t c)
{
    return fix_tone_marker(c, _tone_marker_left_low);
}

uint16_t strip_lower_foot (uint16_t c)
{
    return fix_lower_foot(c, _lower_foot_stripped);
}

uint16_t move_lower_vowel_left (uint16_t c)
{
    return fix_lower_vowel(c, _lower_vowels_left);
}

} // namespace tuftmf
