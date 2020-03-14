#ifndef INSURANCE_COMPANY__COMPANY_H_
#define INSURANCE_COMPANY__COMPANY_H_

#include "insurance.h"

#include <map>
#include <vector>

class Company {
 public:
    void PayTaxes(std::uint32_t taxes_percent);

    void SellInsurances();

    void PayForInsurances();

    std::vector<Insurance> GetOutdatedInsurances() const;

    void UpdateInsurances(std::vector<Insurance> insurances);

 private:
    std::vector<Insurance> insurances_;
    std::map<Insurance, std::uint32_t> sold_insurances_;
    double money_;
};

#endif //INSURANCE_COMPANY__COMPANY_H_
