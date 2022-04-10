#ifndef HEX_CONV_H_
#define HEX_CONV_H_

#include <cassert>
#include <charconv>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>

namespace utils {
std::uint8_t hex_to_decimal_byte(std::string_view hex) {
    assert(hex.length() <= 2);
    std::uint8_t result{};
    const auto err =
        std::from_chars<std::uint8_t>(hex.begin(), hex.end(), result, 16);

    if (err.ec == std::errc::invalid_argument) {
        throw std::runtime_error(std::string{"Failed to parse hex byte "} +
                                 std::string{hex.begin(), hex.end()});
    } else if (err.ec == std::errc::result_out_of_range) {
        throw std::out_of_range(std::string{"Hex byte is out of range at "} +
                                std::string{hex.begin(), hex.end()});
    }

    return result;
}

std::basic_string<std::uint8_t> hex_to_decimal_stream(std::string_view stream) {
    const std::size_t total_len = stream.length();
    const std::size_t remainder = total_len % std::size_t(2);
    std::basic_string<std::uint8_t> ret;
    ret.reserve(total_len / 2);

    for (std::size_t i = 0; i < (total_len - remainder); i += 2) {
        std::string_view section{stream.begin() + i, 2};
        const auto decimal_val = hex_to_decimal_byte(section);
        ret.push_back(decimal_val);
    }

    return ret;
}
}  // namespace utils

#endif /* HEX_CONV_H_ */