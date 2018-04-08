#pragma once
#include "tuftmf.h"

namespace tuftmf
{

bool is_double_quote (char_type c);

bool is_digit (char_type c);

bool is_floating_vowel (char_type c);

bool is_backward_floating_vowel (char_type c);

bool is_tone_marker (char_type c);

bool is_long_tail (char_type c);

bool is_lower_base (char_type c);

bool is_lower_vowel (char_type c);

bool is_lower_tail (char_type c);

char_type move_floating_left (char_type c);

char_type move_tone_marker_low (char_type c);

char_type move_tone_marker_left_height (char_type c);

char_type move_tone_marker_left_low (char_type c);

char_type strip_lower_base (char_type c);

char_type move_lower_vowel_left (char_type c);

} // namespace tuftmf
