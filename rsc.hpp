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

class cvt_utf16 : public std::codecvt<_Tchar, char, _Traits::state_type>
{
protected:
    typedef std::codecvt<_Tchar, char, _Traits::state_type> _TBase;
    typedef _TBase::state_type    state_type;
    typedef _TBase::result        result;

    virtual result do_out (state_type &state,
        const _Tchar *from,
        const _Tchar *from_end,
        const _Tchar* &from_next,
        char *to,
        char *to_limit,
        char* &to_next) const
    {
        if ((state == 0) && (to + 2 <= to_limit))
        {
            to[0] = '\xFF';
            to[1] = '\xFE';
            state = 1;
            to += 2;
        }
        for (; (from < from_end) && (to < to_limit); ++from, to += 2)
        {
            to[0] = reinterpret_cast<const char*>(from)[0];
            to[1] = reinterpret_cast<const char*>(from)[1];
        }
        from_next = from;
        to_next = to;
        return((to > to_limit) ? partial : ok);
    }
}; // class cvt_utf16

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
