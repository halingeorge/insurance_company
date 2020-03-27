#include "base.h"
#include "options.h"
#include "parse.h"

ErrorOr<GameOptions> GameOptions::Init(
    std::string_view company_fund,
    std::string_view federal_taxes_percent,
    std::string_view base_insurance_case_count,
    std::string_view base_customer_count,
    std::string_view game_months) {
  GameOptions options;
  PROPAGATE_ERROR(ParseInt(company_fund, 10000, 30000, "company start fund").AssignTo(options.company_fund));
  PROPAGATE_ERROR(ParseInt(federal_taxes_percent, 0, 10, "federal taxes").AssignTo(options.federal_taxes_percent));
  PROPAGATE_ERROR(ParseInt(base_insurance_case_count,
                           0,
                           10,
                           "base insurance case count").AssignTo(options.base_insurance_case_count));
  PROPAGATE_ERROR(ParseInt(base_customer_count, 0, 1000, "base customer count").AssignTo(options.base_customer_count));
  PROPAGATE_ERROR(ParseInt(game_months, 6, 24, "game duration in months").AssignTo(options.game_months));
  return options;
}
