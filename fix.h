#pragma once
#include <string>
#include <cstdint>
#include <functional>

namespace tuftmf
{

using _Tcounter = std::function<void(uint16_t, uint16_t)>;

void set_fix_counter(_Tcounter counter);

uint16_t fix(uint16_t before, uint16_t current, uint16_t after);

} // namespace tuftmf
