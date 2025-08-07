#include <cctype>
#include <concepts>
#include <optional>

#include "lexer/lexer.h"

namespace kaleidoscope::lexer {

std::variant<char, Token> Lexer::GetToken() {
  // skip whitespace
  do {
    const int input_value = input_.get();
    
    if (input_value >= 0) {
      last_token_ = static_cast<char>(input_value);
    }
  } while (std::holds_alternative<char>(last_token_) &&
           std::isspace(std::get<char>(last_token_)));
}

}
