#include <base64/base64.h>
#include <utils/hex_conv.h>

#include <cstddef>
#include <iostream>

int main() {
    base64::BytesRef bytes{reinterpret_cast<const std::uint8_t *>("a")};
    const auto encoded_str = base64::encode(bytes);
    return EXIT_SUCCESS;
}