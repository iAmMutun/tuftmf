#pragma once
#include <cstdint>

bool is_double_quote (uint16_t c);

bool is_argument (uint16_t c);

bool is_digit (uint16_t c);

bool is_floating_vowel (uint16_t c);

bool is_backward_floating_vowel (uint16_t c);

bool is_tone_marker (uint16_t c);

bool is_long_tail (uint16_t c);

bool is_lower_foot (uint16_t c);

bool is_lower_vowel (uint16_t c);

bool is_lower_tail (uint16_t c);

uint16_t argument_prefix ();

uint16_t move_floating_left (uint16_t c);

uint16_t move_tone_marker_low (uint16_t c);

uint16_t move_tone_marker_left_height (uint16_t c);

uint16_t move_tone_marker_left_low (uint16_t c);

uint16_t strip_lower_foot (uint16_t c);

uint16_t move_lower_vowel_left (uint16_t c);
