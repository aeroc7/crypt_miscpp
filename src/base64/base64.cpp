#include "base64.h"

// https://en.wikipedia.org/wiki/Base64
//
// Base64 is a binary-to-text encoding scheme
// The purpose of this format is to be able to send binary data over a system
// that only supports text. Base64 consists of 64 ASCII characters to represent
// binary data. It is important to note that there is one additional character
// (for a total of 65) that is used for padding ('='). Most commonly, base64 is
// used in email, especially email attachments like images.

namespace base64 {
std::size_t encoded_size(BytesRef buf) noexcept {
    const auto len = buf.length();

    if (len == 0) {
        return 0;
    }

    const auto remain = len % 3;
    unsigned long new_len = len;

    if (remain > 0) {
        new_len += (3 - remain);
    }

    new_len /= 3;
    new_len *= 4;

    return new_len;
}

std::string encode(BytesRef byte_data) {
    [[maybe_unused]] const auto len = byte_data.length();

    return {};
}
}  // namespace base64