#pragma once
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <cstdint>

#include "fix.h"

namespace tuftmf
{

using _Ttraits  = std::char_traits<_Tchar>;
using _Tcvtutf8 = std::codecvt_utf8<_Tchar, 0x10ffff, std::consume_header>;

using istream = std::basic_istream<_Tchar, _Ttraits>;
using ostream = std::basic_ostream<_Tchar, _Ttraits>;

using ifstream = std::basic_ifstream<_Tchar, _Ttraits>;
using ofstream = std::basic_ofstream<_Tchar, _Ttraits>;

using istringstream = std::basic_istringstream<_Tchar, _Ttraits>;
using ostringstream = std::basic_ostringstream<_Tchar, _Ttraits>;

template<class _IStream, class _OStream>
void fix(_IStream& is, _OStream& os)
{
    is.imbue(std::locale(is.getloc(), new _Tcvtutf8));
    os.imbue(std::locale(os.getloc(), new _Tcvtutf8));
    _Tchar before = L'\0', current, after;
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
