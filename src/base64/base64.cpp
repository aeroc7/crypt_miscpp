#include "base64.h"

// https://en.wikipedia.org/wiki/Base64
//
// Base64 is a binary-to-text encoding scheme
// The purpose of this format is to be able to send binary data over a system
// that only supports text. Base64 consists of 64 ASCII characters to represent
// binary data. It is important to note that there is one additional character
// (for a total of 65) that is used for padding ('='). Most commonly, base64 is
// used in email, especially email attachments like images.

namespace base64 {}