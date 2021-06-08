#ifndef CASO_7_PROBABILISTICCRACKER_H
#define CASO_7_PROBABILISTICCRACKER_H

#include <PasswordCracker.h>
#include "PasswordManager.h"
#include <algorithm>

class ProbabilisticCracker: public PasswordCracker{

private:
    PasswordManager passwordManager;

public:
    explicit ProbabilisticCracker(PasswordManager passwordManager) : passwordManager(std::move(passwordManager)){}
    void crack() override;
    string choseRandom();

};

#endif //CASO_7_PROBABILISTICCRACKER_H
