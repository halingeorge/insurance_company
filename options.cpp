#include "base.h"
#include "options.h"
#include "parse.h"

ErrorOr<GameOptions> GameOptions::Init(
    const std::string& company_fund,
    const std::string& federal_taxes_percent,
    const std::string& base_insurance_case_count,
    const std::string& base_customer_count)
{
    GameOptions options;
    PROPAGATE_ERROR(ParseInt(company_fund, 10000, 30000, "company start fund").AssignTo(options.company_fund));
    PROPAGATE_ERROR(ParseInt(federal_taxes_percent, 0, 10, "federal taxes").AssignTo(options.federal_taxes_percent));
    PROPAGATE_ERROR(ParseInt(base_insurance_case_count, 0, 10, "base insurance case count").AssignTo(options.base_insurance_case_count));
    PROPAGATE_ERROR(ParseInt(base_customer_count, 0, 30, "base customer count").AssignTo(options.base_customer_count));
    return options;
}
