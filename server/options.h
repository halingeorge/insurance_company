#ifndef INSURANCE_COMPANY_SERVER_OPTIONS_H_
#define INSURANCE_COMPANY_SERVER_OPTIONS_H_

#include <cstdint>

struct Options {
    std::uint32_t FederalTaxesPercent;
    std::uint32_t GameDayCount;
};

#endif //INSURANCE_COMPANY_SERVER_OPTIONS_H_
