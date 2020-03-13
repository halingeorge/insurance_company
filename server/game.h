#ifndef INSURANCE_COMPANY__GAME_H_
#define INSURANCE_COMPANY__GAME_H_

#include "company.h"
#include "options.h"

class Game {
 public:
    void PlayOneDay();

    bool HasGameFinished() const;

    bool HasCompanyWon() const;

    bool HasCompanyLost() const;

    void SetOptions(Options options);

 private:
    Options options_;
    Company company_;
};

#endif //INSURANCE_COMPANY__GAME_H_
