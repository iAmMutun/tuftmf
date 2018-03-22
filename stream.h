#pragma once
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <cstdint>

#include "fix.h"

namespace tuftmf
{

using _Ttraits  = std::char_traits<char_type>;
using _Tcvtutf8 = std::codecvt_utf8<char_type, 0x10ffff, std::consume_header>;

using istream = std::basic_istream<char_type, _Ttraits>;
using ostream = std::basic_ostream<char_type, _Ttraits>;

using ifstream = std::basic_ifstream<char_type, _Ttraits>;
using ofstream = std::basic_ofstream<char_type, _Ttraits>;

using istringstream = std::basic_istringstream<char_type, _Ttraits>;
using ostringstream = std::basic_ostringstream<char_type, _Ttraits>;

template<class _IStream, class _OStream>
void fix(_IStream& is, _OStream& os)
{
    is.imbue(std::locale(is.getloc(), new _Tcvtutf8));
    os.imbue(std::locale(os.getloc(), new _Tcvtutf8));
    char_type before = L'\0', current, after;
    is.get(current);
    while (!is.eof())
    {
        is.get(after);
        current = fix(before, current, after);
        os.put(current);
        before = current;
        current = after;
    } // while
}

} // namespace tuftmf
