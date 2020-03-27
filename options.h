#ifndef INSURANCE_COMPANY_SERVER_OPTIONS_H_
#define INSURANCE_COMPANY_SERVER_OPTIONS_H_

#include "error.h"

#include <optional>
#include <cstdint>
#include <string>

struct GameOptions {
  std::uint32_t company_fund;
  std::uint32_t federal_taxes_percent;
  std::uint32_t base_insurance_case_count;
  std::uint32_t base_customer_count;
  std::uint32_t game_months;

  static ErrorOr<GameOptions> Init(
      std::string_view company_fund,
      std::string_view federal_taxes_percent,
      std::string_view base_insurance_case_count,
      std::string_view base_customer_count,
      std::string_view game_months);
};

#endif //INSURANCE_COMPANY_SERVER_OPTIONS_H_
