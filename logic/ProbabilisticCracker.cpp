#include <FileManager.h>
#include "ProbabilisticCracker.h"

#include <vector>

void ProbabilisticCracker::crack() {

    int attempt = 0;
    int size = passwordManager.passwordsHistogram.size();
    for (int i = 0; i < size; ++i, ++attempt) {

        string password = choseRandom();

        if(FileManager::isPasswordCorrect(password)) { // test
            std::cout << "---> password was correct, attempt: " << attempt << "\tpassword:" << password << std::endl;
            return;
        }else
            std::cout << "password was incorrect, attempt: " << attempt << "\tpassword:" << password  << std::endl;

    }

}

string ProbabilisticCracker::choseRandom() {

    // select random key
    int randomPosition = rand() % passwordManager.passwords.size();
    auto it = passwordManager.passwords.begin();
    advance(it, randomPosition);

    string randomKey = *it;

    // remove selected key
    passwordManager.passwordsHistogram.erase(randomKey);
    passwordManager.passwords.remove(randomKey);

    return randomKey;
}