#ifndef PARSE_H
#define PARSE_H

#include "error.h"

#include <string>
#include <limits>

ErrorOr<int> ParseInt(std::string_view number, int min_limit = std::numeric_limits<int>::min(),
                      int max_limit = std::numeric_limits<int>::max(), std::string_view error_prefix = "");

#endif // PARSE_H
