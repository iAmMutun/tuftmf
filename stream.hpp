#pragma once
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <cstdint>

namespace tuftmf
{
using _Tchar    = uint16_t;
using _Ttraits  = std::char_traits<_Tchar>;
using _Tifbase  = std::basic_ifstream<_Tchar, _Ttraits>;
using _Tofbase  = std::basic_ofstream<_Tchar, _Ttraits>;
using _Tcvtutf8 = std::codecvt_utf8<_Tchar, 0x10ffff, std::consume_header>;

class ifstream : public _Tifbase
{
public:
    ifstream (const std::wstring &file)
        : _Tifbase(file, std::ios::binary)
    {
        _Tcvtutf8 *cvt = new _Tcvtutf8;
        imbue(std::locale(getloc(), cvt));
    };
}; // class istream

class ofstream : public _Tofbase
{
public:
    ofstream (const std::wstring &file)
        : _Tofbase(file, std::ios::binary)
    {
        _Tcvtutf8 *cvt = new _Tcvtutf8;
        imbue(std::locale(getloc(), cvt));
    };
}; // class ofstream

} // namespace tuftmf
