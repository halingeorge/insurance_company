#include "parse.h"

ErrorOr<int> ParseInt(const std::string& number, int min_limit, int max_limit, const std::string& error_prefix)
{
    auto print_error_prefix = [&]() -> std::string {
        if (error_prefix.empty()) {
            return "";
        }
        return error_prefix + ": ";
    };
    int result;
    try {
        result = std::stoi(number);
    } catch (const std::exception& ex) {
        return MakeError(print_error_prefix() + "unable to parse: " + number + " with error: " + ex.what());
    }
    VERIFY(min_limit <= result && result <= max_limit,
           print_error_prefix() << "out of range [" << min_limit << ", " << max_limit << "]");
    return result;
}
