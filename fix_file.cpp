#include <iostream>
#include <locale>
#include "functions.h"
#include "stream.hpp"

void fix_file (const std::wstring& in, const std::wstring& out)
{
    std::wcout << L"in:" << in << L"\nout:" << out << L'\n';
    tuftmf::istream fsin(in);
    tuftmf::ostream fsout(out);

    int count = 0;
    wchar_t before = L'\0';
    wchar_t current, after;
    fsin.get(current);
    while (!fsin.eof())
    {
        fsin.get(after);

        if (is_floating_vowel(current))
        {
            if (is_long_tail(before))
            {
                count++;
                current = move_floating_left(current);
            }
        }
        else if (is_floating_vowel(current))
        {
            if (is_long_tail(before))
            {
                count++;
                current = move_floating_left(current);
            }
        }
        else if (is_tone_marker(current))
        {
            if (is_floating_vowel(before))
            {
                if (is_long_tail(before))
                {
                    count++;
                    current = move_tone_marker_left_height(current);
                }
            }
            else if (is_long_tail(before))
            {
                if (is_backward_floating_vowel(after))
                {
                    count++;
                    current = move_tone_marker_left_height(current);
                }
                else
                {
                    count++;
                    current = move_tone_marker_left_low(current);
                }
            }
            else if (!is_backward_floating_vowel(after))
            {
                count++;
                current = move_tone_marker_low(current);
            }
        }
        else if (is_lower_foot(current))
        {
            if (is_lower_vowel(after))
            {
                count++;
                current = strip_lower_foot(current);
            }
        }
        else if (is_lower_vowel(current))
        {
            if (is_lower_tail(before))
            {
                count++;
                current = move_lower_vowel_left(current);
            }
        }

        fsout.put(current);

        if (is_digit(current))
        {
            if (is_argument(before) && is_argument(after))
            {
                count++;
                fsout.put(argument_prefix());
            }
        }

        before = current;
        current = after;
    } // while

    if (count > 0)
        std::wcout << L'\n';
    std::wcout << L"fixed:" << count << std::endl;
}
