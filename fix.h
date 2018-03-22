#pragma once
#include <cstdint>
#include <functional>

namespace tuftmf
{

using char_type = uint16_t;

using counter_type = std::function<void(char_type, char_type)>;

void set_fix_counter(counter_type counter);

char_type fix(char_type before, char_type current, char_type after);

} // namespace tuftmf
