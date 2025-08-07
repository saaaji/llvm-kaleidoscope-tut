#include <cstdint>
#include <iostream>
#include <string>
#include <variant>

namespace kaleidoscope::lexer {

enum class Token : std::uint8_t {
  kEof,
  kDef,
  kExtern,
  kIdentifier,
  kNumber
};

class Lexer {
public:
  Lexer(std::istream& input) : input_(input) {}

  std::variant<char, Token> GetToken();

private:
  std::istream& input_;
  std::pair<std::string, bool> identifier_str_{};
  std::pair<double, bool> num_val_{};
  std::variant<char, Token> last_token_{Token::kEof};
};

}
