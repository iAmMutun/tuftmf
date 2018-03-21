#include "functions.h"
#include "stream.hpp"
#include "fix.h"

namespace tuftmf
{

_Tcounter _null_counter = [] (uint16_t, uint16_t) {};
_Tcounter _fix_counter  = _null_counter;

void set_fix_counter(_Tcounter counter)
{
    _fix_counter = (counter ? counter : _null_counter);
}

uint16_t fix(uint16_t before, uint16_t current, uint16_t after)
{
    if (is_floating_vowel(current))
    {
        if (is_long_tail(before))
        {
            current = move_floating_left(current);
        }
    }
    else if (is_floating_vowel(current))
    {
        if (is_long_tail(before))
        {
            current = move_floating_left(current);
        }
    }
    else if (is_tone_marker(current))
    {
        if (is_floating_vowel(before))
        {
            if (is_long_tail(before))
            {
                current = move_tone_marker_left_height(current);
            }
        }
        else if (is_long_tail(before))
        {
            if (is_backward_floating_vowel(after))
            {
                current = move_tone_marker_left_height(current);
            }
            else
            {
                current = move_tone_marker_left_low(current);
            }
        }
        else if (!is_backward_floating_vowel(after))
        {
            current = move_tone_marker_low(current);
        }
    }
    else if (is_lower_foot(current))
    {
        if (is_lower_vowel(after))
        {
            current = strip_lower_foot(current);
        }
    }
    else if (is_lower_vowel(current))
    {
        if (is_lower_tail(before))
        {
            current = move_lower_vowel_left(current);
        }
    }
    return current;
}

void fix_file (const std::wstring& in, const std::wstring& out)
{
    tuftmf::ifstream fsin(in);
    tuftmf::ofstream fsout(out);

    uint16_t before = L'\0';
    uint16_t current, after;
    fsin.get(current);
    while (!fsin.eof())
    {
        fsin.get(after);

        uint16_t new_current;
        new_current = fix(before, current, after);

        if (new_current != current)
        {
            current = new_current;
            _fix_counter(current, new_current);
        }

        fsout.put(current);

        before = current;
        current = after;
    } // while
}

} // namespace tuftmf
