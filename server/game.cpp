#include "game.h"
#include "error.h"

void Game::Init(GameOptions options) {
  options_ = std::move(options);
  played_months_ = 0;
  company_.Init(options_.company_fund);
}

bool Game::PlayOneMonth() {
  ++played_months_;
  company_.UpdateInsurancesLiveTime();
  company_.PayTaxes(options_.federal_taxes_percent);
  company_.SellInsurances(options_.base_customer_count);
  return company_.PayForInsurances(options_.base_insurance_case_count);
}

bool Game::HasCompanyLost() const {
  return company_.GetMoney() < 0;
}

bool Game::HasGameFinished() const {
  return played_months_ >= options_.game_months;
}

Company& Game::GetCompany() {
  return company_;
}
