#ifndef INSURANCE_COMPANY__INSURANCE_H_
#define INSURANCE_COMPANY__INSURANCE_H_

#include <cstdint>

class Insurance {
 public:
    enum class Type {
        House,
        Car,
        Health,

        Size
    };

    enum class PaymentFrequency {
        Month,
        Quarter,
        Year,

        Size
    };

    Insurance(Type type, PaymentFrequency payment_frequency, std::uint32_t price, std::uint32_t months_duration,
        std::uint32_t demand, std::uint32_t min_insurance_money_amount, std::uint32_t max_insurance_money_amount);

    std::uint32_t GetDemand() const;
    void SetDemand(std::uint32_t demand);

 private:
    Type type_;
    PaymentFrequency payment_frequency_;
    double price_per_month_;
    std::uint32_t months_duration_;
    std::uint32_t demand_;
    std::uint32_t min_insurance_money_amount_;
    std::uint32_t max_insurance_money_amount_;
};

#endif //INSURANCE_COMPANY__INSURANCE_H_
