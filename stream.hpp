#pragma once
#include <fstream>
#include <locale>
#include <codecvt>

namespace rsc
{

typedef char16_t _Tchar;
typedef std::char_traits<_Tchar> _Traits;

class cvt_utf8 : public std::codecvt_utf8<_Tchar, 0x10ffff, std::consume_header>
{
}; // class cvt_utf8

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

} // namespace rsc
