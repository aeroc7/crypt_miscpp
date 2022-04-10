#ifndef BYTE_LITERAL_H_
#define BYTE_LITERAL_H_

#include <cstddef>

inline constexpr std::byte operator"" _byte(char arg) noexcept {
    return static_cast<std::byte>(arg);
}

#endif /* BYTE_LITERAL_H_ */