#include "insurance.h"
#include "parse.h"

ErrorOr<Insurance> Insurance::Init(Type type,
                                   std::string_view price_str,
                                   std::string_view duration,
                                   std::string_view min_insurance_money_amount,
                                   std::string_view max_insurance_money_amount,
                                   std::string_view payment_frequency) {
  DEBUG("new insurance");

  Insurance insurance;
  insurance.type_ = type;

  PROPAGATE_ERROR(ParseInt(price_str, 50, 5000, "insurance price").AssignTo(insurance.period_price_));
  PROPAGATE_ERROR(ParseInt(duration, 2, 12, "insurance months duration").AssignTo(insurance.months_duration_));
  PROPAGATE_ERROR(ParseInt(min_insurance_money_amount,
                           100,
                           20000,
                           "insurance min price").AssignTo(insurance.min_insurance_money_amount_));
  PROPAGATE_ERROR(ParseInt(max_insurance_money_amount,
                           insurance.min_insurance_money_amount_,
                           20000,
                           "insurance max price").AssignTo(insurance.max_insurance_money_amount_));
  PROPAGATE_ERROR(ParseInt(payment_frequency,
                           1,
                           12,
                           "insurance payment frequency").AssignTo(insurance.payment_frequency_));

  insurance.price_ = static_cast<double>(insurance.period_price_) / insurance.payment_frequency_;

  return insurance;
}

double Insurance::GetDemand() const {
  double demand = 10.0 * max_insurance_money_amount_ / (1.0 * period_price_ * min_insurance_money_amount_);
  demand = std::max(0.0, demand);
  demand = std::min(1.0, demand);
  return demand;
}

Insurance::Type Insurance::GetType() const {
  return type_;
}

bool Insurance::HasExpired() const {
  DEBUG("live_time: " << live_time_ << " months_duration: " << months_duration_);
  return live_time_ >= months_duration_;
}