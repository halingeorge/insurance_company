#include "company.h"
#include "base.h"

#include <unordered_set>

void Company::Init(std::uint32_t company_fund) {
  insurances_.clear();
  sold_insurances_.clear();
  DEBUG("company_fund: " << company_fund);
  money_ = company_fund;
}

void Company::PayTaxes(std::uint32_t taxes_percent) {
  money_ *= 1.0 - taxes_percent / 100.0;
}

std::vector<Insurance::Type> Company::GetOutdatedInsurances() const {
  std::vector<Insurance::Type> outdated_insurances;
  std::vector<bool> considered(static_cast<size_t>(Insurance::Type::Size), false);
  for (const auto& insurance : insurances_) {
    if (insurance.HasExpired()) {
      outdated_insurances.push_back(insurance.GetType());
    }
    considered[static_cast<size_t>(insurance.GetType())] = true;
  }
  for (size_t i = 0; i < static_cast<size_t>(Insurance::Type::Size); i++) {
    if (!considered[i]) {
      outdated_insurances.push_back(static_cast<Insurance::Type>(i));
    }
  }
  for (auto type : outdated_insurances) {
    DEBUG("outdated insurance type: " << static_cast<size_t>(type));
  }
  return outdated_insurances;
}

void Company::UpdateInsurancesLiveTime() {
  for (auto& insurance : insurances_) {
    insurance.IncrementLiveTime();
  }
}

void Company::UpdateInsurances(std::vector<Insurance> insurances) {
  if (insurances_.empty()) {
    insurances_ = std::move(insurances);
    return;
  }
  for (auto&& insurance : insurances) {
    auto index = static_cast<size_t>(insurance.GetType());
    DEBUG("update insurance: " << index);
    insurances_[index] = std::move(insurance);
  }
}

void Company::SellInsurances(std::uint32_t base_customer_count) {
  DEBUG("money: " << money_);
  for (const auto& insurance : insurances_) {
    auto sold_count = floor(insurance.GetDemand() * base_customer_count);
    DEBUG("demand: " << insurance.GetDemand());
    sold_insurances_[insurance.GetType()] += sold_count;
    profit_by_insurance_[insurance.GetType()] += sold_count * insurance.GetPricePerMonth();
    money_ += sold_count * insurance.GetPricePerMonth();
    DEBUG("sold_count: " << sold_count << " profit: " << sold_count * insurance.GetPricePerMonth());
  }
  DEBUG("money: " << money_);
}

bool Company::PayForInsurances(std::uint32_t base_insurance_case_count) {
  for (const auto& insurance : insurances_) {
    int insurance_cases = rand() % (base_insurance_case_count + 1);
    insurance_cases_by_type_[insurance.GetType()] += insurance_cases;
    for (size_t i = 0; i < insurance_cases; i++) {
      double r = rand() % 100 / 100.0;
      int damage_price = insurance.GetMaxInsuranceMoneyAmount() * r;
      if (damage_price < insurance.GetMinInsuranceMoneyAmount()) {
        continue;
      }
      money_ -= damage_price;
      if (money_ < 0) {
        return false;
      }
      profit_by_insurance_[insurance.GetType()] -= damage_price;
      DEBUG("damage_price: " << damage_price);
    }
    DEBUG("money: " << money_);
  }
  return true;
}