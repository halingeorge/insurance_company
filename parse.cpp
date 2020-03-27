#include "parse.h"

#include <string_view>

ErrorOr<int> ParseInt(std::string_view number, int min_limit, int max_limit, std::string_view error_prefix) {
    auto print_error_prefix = [&]() -> std::string {
      if (error_prefix.empty()) {
          return "";
      }
      return std::string(error_prefix) + ": ";
    };
    int result;
    try {
        result = std::stoi(std::string(number));
    } catch (const std::exception& ex) {
        return MakeError(
            print_error_prefix() + "unable to parse: " + std::string(number) + " with error: " + ex.what());
    }
    VERIFY(min_limit <= result && result <= max_limit,
           print_error_prefix() << "out of range [" << min_limit << ", " << max_limit << "]");
    return result;
}
