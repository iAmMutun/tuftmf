#pragma once
#include <fstream>
#include <locale>
#include <codecvt>
#include <cstdint>

namespace tuftmf
{
using _Tchar   = uint16_t;
using _Traits  = std::char_traits<_Tchar>;
using cvt_utf8 = std::codecvt_utf8<_Tchar, 0x10ffff, std::consume_header>;

class istream : public std::basic_ifstream<_Tchar, _Traits>
{
protected:
    typedef std::basic_ifstream<_Tchar, _Traits> _Tbase;
public:
    istream (const std::wstring &file) : _Tbase(file, std::ios::binary)
    {
        cvt_utf8 *cvt = new cvt_utf8;
        imbue(std::locale(getloc(), cvt));
    };
}; // class istream

class ostream : public std::basic_ofstream<_Tchar, _Traits>
{
protected:
    typedef std::basic_ofstream<_Tchar, _Traits> _Tbase;
public:
    ostream (const std::wstring &file) : _Tbase(file, std::ios::binary)
    {
        cvt_utf8 *cvt = new cvt_utf8;
        imbue(std::locale(getloc(), cvt));
    };
}; // class ostream

} // namespace tuftmf
