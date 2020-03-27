#ifndef INSURANCE_COMPANY__INSURANCE_H_
#define INSURANCE_COMPANY__INSURANCE_H_

#include "base.h"
#include "error.h"

#include <cstdint>
#include <vector>
#include <string_view>

class Insurance {
 public:
  enum class Type {
    House,
    Car,
    Health,

    Size
  };

  static ErrorOr<Insurance> Init(Type type,
                                 std::string_view price,
                                 std::string_view duration,
                                 std::string_view min_insurance_money_amount,
                                 std::string_view max_insurance_money_amount,
                                 std::string_view payment_frequency);

  double GetDemand() const;

  Type GetType() const;

  bool HasExpired() const;

  double GetPricePerMonth() const {
    return price_;
  }

  double GetMinInsuranceMoneyAmount() const {
    return min_insurance_money_amount_;
  }

  double GetMaxInsuranceMoneyAmount() const {
    return max_insurance_money_amount_;
  }

  void IncrementLiveTime() {
    live_time_ += 1;
  }

 public:
  static constexpr size_t ParameterCount = 5;

 private:
  Type type_;
  double price_;
  std::uint32_t period_price_;
  std::uint32_t months_duration_;
  std::uint32_t min_insurance_money_amount_;
  std::uint32_t max_insurance_money_amount_;
  std::uint32_t payment_frequency_;
  std::uint32_t live_time_ = 0;
};

#endif //INSURANCE_COMPANY__INSURANCE_H_
