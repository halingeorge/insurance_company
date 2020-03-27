#ifndef INSURANCE_COMPANY__COMPANY_H_
#define INSURANCE_COMPANY__COMPANY_H_

#include "insurance.h"

#include <map>
#include <vector>

class Company {
 public:
  void Init(std::uint32_t company_fund);

  void PayTaxes(std::uint32_t taxes_percent);

  std::vector<Insurance::Type> GetOutdatedInsurances() const;

  void UpdateInsurancesLiveTime();

  void UpdateInsurances(std::vector<Insurance> insurances);

  void SellInsurances(std::uint32_t base_customer_count);

  bool PayForInsurances(std::uint32_t base_insurance_case_count);

  double GetMoney() const {
    return money_;
  }

  const std::map<Insurance::Type, std::uint32_t>& GetSoldInsurances() const {
    return sold_insurances_;
  }

  const std::map<Insurance::Type, double>& GetProfitByInsurance() const {
    return profit_by_insurance_;
  }

  const std::map<Insurance::Type, std::uint32_t>& GetInsuranceCasesByType() const {
    return insurance_cases_by_type_;
  }

 private:
  std::vector<Insurance> insurances_;
  std::map<Insurance::Type, std::uint32_t> sold_insurances_;
  std::map<Insurance::Type, double> profit_by_insurance_;
  std::map<Insurance::Type, std::uint32_t> insurance_cases_by_type_;
  double money_;
};

#endif //INSURANCE_COMPANY__COMPANY_H_
