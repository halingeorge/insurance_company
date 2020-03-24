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

    static ErrorOr<GameOptions> Init(
        const std::string& company_fund,
        const std::string& federal_taxes_percent,
        const std::string& base_insurance_case_count,
        const std::string& base_customer_count);
};

#endif //INSURANCE_COMPANY_SERVER_OPTIONS_H_
