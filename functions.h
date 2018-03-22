#pragma once
#include "fix.h"

namespace tuftmf
{

bool is_double_quote (_Tchar c);

bool is_argument (_Tchar c);

bool is_digit (_Tchar c);

bool is_floating_vowel (_Tchar c);

bool is_backward_floating_vowel (_Tchar c);

bool is_tone_marker (_Tchar c);

bool is_long_tail (_Tchar c);

bool is_lower_foot (_Tchar c);

bool is_lower_vowel (_Tchar c);

bool is_lower_tail (_Tchar c);

_Tchar move_floating_left (_Tchar c);

_Tchar move_tone_marker_low (_Tchar c);

_Tchar move_tone_marker_left_height (_Tchar c);

_Tchar move_tone_marker_left_low (_Tchar c);

_Tchar strip_lower_foot (_Tchar c);

_Tchar move_lower_vowel_left (_Tchar c);

} // namespace tuftmf
