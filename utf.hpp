#pragma once
#include <locale>
#include <codecvt>

class rsc_utf8 : public std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>
{ };

class rsc_utf16 : public std::codecvt<wchar_t, char, std::char_traits<wchar_t>::state_type>
{
  typedef std::codecvt<wchar_t, char, std::char_traits<wchar_t>::state_type> _Tbase;
  typedef _Tbase::state_type    state_type;
  typedef _Tbase::result        result;

  virtual result do_out(state_type &state,
              const wchar_t *from,
              const wchar_t *from_end,
              const wchar_t* &from_next,
              char *to,
              char *to_limit,
              char* &to_next) const
  {
    if ((state == 0) && (to + 2 <= to_limit)) {
      to[0] = '\xFF';
      to[1] = '\xFE';
      state = 1;
      to += 2;
    }
    for(;(from < from_end) && (to < to_limit); ++from, to += 2) {
      to[0] = reinterpret_cast<const char*>(from)[0];
      to[1] = reinterpret_cast<const char*>(from)[1];
    }
    from_next = from;
    to_next   = to;
    return((to > to_limit)? partial : ok);
  }
};
