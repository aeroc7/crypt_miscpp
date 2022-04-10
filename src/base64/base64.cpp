#include "base64.h"

#include <utils/byte_literal.h>

#include <array>
#include <iostream>

// https://en.wikipedia.org/wiki/Base64
//
// Base64 is a binary-to-text encoding scheme
// The purpose of this format is to be able to send binary data over a system
// that only supports text. Base64 consists of 64 ASCII characters to represent
// binary data. It is important to note that there is one additional character
// (for a total of 65) that is used for padding ('='). Most commonly, base64 is
// used in email, especially email attachments like images.

namespace base64 {
constexpr auto DECODED_BYTE_SIZE = 3;
constexpr auto ENCODED_BYTE_SIZE = 4;
constexpr auto B64_PADDING_CHAR = '='_byte;
constexpr std::array<std::byte, 64> B64_TABLE = {'A'_byte, 'B'_byte, 'C'_byte,
    'D'_byte, 'E'_byte, 'F'_byte, 'G'_byte, 'H'_byte, 'I'_byte, 'J'_byte,
    'K'_byte, 'L'_byte, 'M'_byte, 'N'_byte, 'O'_byte, 'P'_byte, 'Q'_byte,
    'R'_byte, 'S'_byte, 'T'_byte, 'U'_byte, 'V'_byte, 'W'_byte, 'X'_byte,
    'Y'_byte, 'Z'_byte, 'a'_byte, 'b'_byte, 'c'_byte, 'd'_byte, 'e'_byte,
    'f'_byte, 'g'_byte, 'h'_byte, 'i'_byte, 'j'_byte, 'k'_byte, 'l'_byte,
    'm'_byte, 'n'_byte, 'o'_byte, 'p'_byte, 'q'_byte, 'r'_byte, 's'_byte,
    't'_byte, 'u'_byte, 'v'_byte, 'w'_byte, 'x'_byte, 'y'_byte, 'z'_byte,
    '0'_byte, '1'_byte, '2'_byte, '3'_byte, '4'_byte, '5'_byte, '6'_byte,
    '7'_byte, '8'_byte, '9'_byte, '+'_byte, '/'_byte};

std::size_t encoded_size(std::size_t len) noexcept {
    if (len == 0) {
        return 0;
    }

    const auto remain = len % DECODED_BYTE_SIZE;
    unsigned long new_len = len;

    if (remain > 0) {
        new_len += (DECODED_BYTE_SIZE - remain);
    }

    new_len /= DECODED_BYTE_SIZE;
    new_len *= ENCODED_BYTE_SIZE;

    return new_len;
}

std::string encode(BytesRef byte_data) {
    const auto len = byte_data.length();
    const auto len_padding = len % DECODED_BYTE_SIZE;
    const auto encoded_len = encoded_size(len);
    const auto last_even_block = (len - len_padding);

    std::string encoded_buf;
    encoded_buf.reserve(encoded_len);

    std::cout << len << '\n';
    std::cout << len_padding << '\n';

    for (std::size_t i = 0; i < last_even_block; ++i) {
    }

    // Encode last bytes and pad appropriately
    /*if (len_padding > 0) {
        std::uint32_t encoded_part{};
        for (std::size_t i = last_even_block; i < len; ++i) {
            byte_data
        }
    }*/

    return encoded_buf;
}
}  // namespace base64