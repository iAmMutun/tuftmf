#include "functions.h"
#include "tuftmf.h"

namespace tuftmf
{

counter_type _null_counter = [] (char_type, char_type) {};
counter_type _fix_counter  = _null_counter;

void set_fix_counter(counter_type counter)
{
    _fix_counter = (counter ? counter : _null_counter);
}

char_type fix(char_type before, char_type current, char_type after)
{
    uint16_t new_current = current;
    if (is_floating_vowel(current))
    {
        if (is_long_tail(before))
        {
            new_current = move_floating_left(current);
        }
    }
    else if (is_floating_vowel(current))
    {
        if (is_long_tail(before))
        {
            new_current = move_floating_left(current);
        }
    }
    else if (is_tone_marker(current))
    {
        if (is_floating_vowel(before))
        {
            if (is_long_tail(before))
            {
                new_current = move_tone_marker_left_height(current);
            }
        }
        else if (is_long_tail(before))
        {
            if (is_backward_floating_vowel(after))
            {
                new_current = move_tone_marker_left_height(current);
            }
            else
            {
                new_current = move_tone_marker_left_low(current);
            }
        }
        else if (!is_backward_floating_vowel(after))
        {
            new_current = move_tone_marker_low(current);
        }
    }
    else if (is_lower_foot(current))
    {
        if (is_lower_vowel(after))
        {
            new_current = strip_lower_foot(current);
        }
    }
    else if (is_lower_vowel(current))
    {
        if (is_lower_tail(before))
        {
            new_current = move_lower_vowel_left(current);
        }
    }
    if (current != new_current)
        _fix_counter(current, new_current);
    return new_current;
}

} // namespace tuftmf
