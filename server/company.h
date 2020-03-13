#ifndef INSURANCE_COMPANY__COMPANY_H_
#define INSURANCE_COMPANY__COMPANY_H_

#include "insurance.h"

#include <vector>

class Company {
 public:
    void PayTaxes(std::uint32_t taxes_percent);

    void SellInsurances();

    void PayForInsurances();

    std::vector<Insurance> GetOutdatedInsurances() const;

    void AddInsurance(Insurance insurance);

 private:
    std::vector<Insurance> insurances_;
    double money_;
};

#endif //INSURANCE_COMPANY__COMPANY_H_
