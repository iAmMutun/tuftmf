#pragma once

bool is_floating_vowel (wchar_t c);

bool is_backward_floating_vowel (wchar_t c);

bool is_tone_marker (wchar_t c);

bool is_long_tail (wchar_t c);

bool is_lower_foot (wchar_t c);

bool is_lower_vowel (wchar_t c);

bool is_lower_tail (wchar_t c);

wchar_t fix_floating_vowel (wchar_t c, const wchar_t *fix);

wchar_t fix_tone_marker (wchar_t c, const wchar_t *fix);

wchar_t fix_lower_foot (wchar_t c, const wchar_t *fix);

wchar_t fix_lower_vowel (wchar_t c, const wchar_t *fix);
