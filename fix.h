#pragma once
#include <cstdint>
#include <functional>

namespace tuftmf
{

using _Tchar = uint16_t;

using _Tcounter = std::function<void(_Tchar, _Tchar)>;

void set_fix_counter(_Tcounter counter);

_Tchar fix(_Tchar before, _Tchar current, _Tchar after);

} // namespace tuftmf
