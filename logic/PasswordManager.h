
#ifndef CASO_7_PASSWORDMANAGER_H
#define CASO_7_PASSWORDMANAGER_H

#include <map>
#include <Node.h>
#include <vector>
#include <list>

using namespace std;

class PasswordManager {

public:
    std::map<std::string, int> passwordsHistogram;
    //std::vector<std::string> passwords;
    list<std::string> passwords;
    std::map<char, int> lexicographically;

public:
    PasswordManager() {

        lexicographically = {
                {'0',0},
                {'1', 1},
                {'2', 2},
                {'A', 3},
                {'B', 4},
                {'F', 5},
                {'K', 6}
        };

    }

    void generatePasswords(std::vector<Node*> &pNodes);

    bool isGrater(const char &pA, const char &pB) {
        return lexicographically[pA] > lexicographically[pB];
    }

private:
    std::vector<std::string> getPasswordFromNode(Node* &pNode, const char &pPast);
    void addCharToStartOfAllStrings(const char &pChar, std::vector<std::string> &pStrings);
};


#endif //CASO_7_PASSWORDMANAGER_H
