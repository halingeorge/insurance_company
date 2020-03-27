#ifndef INSURANCE_COMPANY__GAME_H_
#define INSURANCE_COMPANY__GAME_H_

#include "company.h"
#include "options.h"

class Game {
 public:
  Game() = default;

  void Init(GameOptions options);

  bool PlayOneMonth();

  bool HasCompanyLost() const;

  bool HasGameFinished() const;

  Company& GetCompany();

  size_t GetPlayedMonth() const {
    return played_months_;
  }

 private:
  GameOptions options_;
  Company company_;
  size_t played_months_ = 0;
};

#endif //INSURANCE_COMPANY__GAME_H_
