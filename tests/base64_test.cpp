#include <base64/base64.h>
#include <gtest/gtest.h>

TEST(Base64EncodedSize, BufSizeParam0) {
    const auto sz = base64::encoded_size({});
    ASSERT_EQ(sz, 0);
}

TEST(Base64EncodedSize, BufSizeParam1) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>("a")};
    const auto sz = base64::encoded_size(bref.length());
    ASSERT_EQ(sz, 4);
}

TEST(Base64EncodedSize, BufSizeParam2) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>("ab")};
    const auto sz = base64::encoded_size(bref.length());
    ASSERT_EQ(sz, 4);
}

TEST(Base64EncodedSize, BufSizeParam3) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>("abc")};
    const auto sz = base64::encoded_size(bref.length());
    ASSERT_EQ(sz, 4);
}

TEST(Base64EncodedSize, BufSizeParam4) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>("abcd")};
    const auto sz = base64::encoded_size(bref.length());
    ASSERT_EQ(sz, 8);
}

TEST(Base64EncodedSize, BufSizeParam60) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>(
        "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd")};
    const auto sz = base64::encoded_size(bref.length());
    ASSERT_EQ(sz, 80);
}

TEST(Base64Encode, DataSize1) {
    base64::BytesRef bref{reinterpret_cast<const std::uint8_t *>("a")};
    const auto encoded_data = base64::encode(bref);
    ASSERT_EQ(encoded_data.size(), 4);
}
