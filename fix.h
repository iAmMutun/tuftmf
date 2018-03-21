#pragma once
#include <string>
#include <cstdint>

namespace tuftmf
{

uint16_t fix(uint16_t before, uint16_t current, uint16_t after);

void fix_file(const std::wstring& in, const std::wstring& out);

} // namespace tuftmf
