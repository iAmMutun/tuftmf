#pragma once

bool is_floating_vowel (wchar_t c);

bool is_backward_floating_vowel (wchar_t c);

bool is_tone_marker (wchar_t c);

bool is_long_tail (wchar_t c);

bool is_lower_foot (wchar_t c);

bool is_lower_vowel (wchar_t c);

bool is_lower_tail (wchar_t c);

wchar_t move_floating_left (wchar_t c);

wchar_t move_tone_marker_low (wchar_t c);

wchar_t move_tone_marker_left_height (wchar_t c);

wchar_t move_tone_marker_left_low (wchar_t c);

wchar_t strip_lower_foot (wchar_t c);

wchar_t move_lower_vowel_left (wchar_t c);
