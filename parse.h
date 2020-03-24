#ifndef PARSE_H
#define PARSE_H

#include "error.h"

#include <string>
#include <limits>

ErrorOr<int> ParseInt(const std::string& number, int min_limit = std::numeric_limits<int>::min(),
                      int max_limit = std::numeric_limits<int>::max(), const std::string& error_prefix = "");

#endif // PARSE_H
