#ifndef BASE64_H_
#define BASE64_H_

#include <cstdint>
#include <string>
#include <string_view>

namespace base64 {
using BytesRef = std::basic_string_view<std::uint8_t>;

std::size_t encoded_size(BytesRef buf) noexcept;
std::string encode(BytesRef buf);
}  // namespace base64

#endif /* BASE64_H_ */