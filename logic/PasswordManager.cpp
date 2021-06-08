#include "PasswordManager.h"
#include "iostream"

void PasswordManager::generatePasswords(std::vector<Node *> &pNodes) {

    for(auto &node: pNodes) {
        std::vector<std::string> passwordNode = getPasswordFromNode(node, '0');
        passwords.insert(passwords.end(), passwordNode.begin(), passwordNode.end());
    }

    for(std::string &s: passwords)
        passwordsHistogram[s]++;
}

std::vector<std::string> PasswordManager::getPasswordFromNode(Node *&pNode, const char &pPast) {
    std::vector<std::string> rs;

    for(auto &arc: pNode->relations) {

        if(isGrater(arc.first, pPast)) {

            std::vector<std::string> pas = getPasswordFromNode(arc.second, arc.first);

            if(!pas.empty()) {

                addCharToStartOfAllStrings(arc.first, pas);
                rs.insert(rs.end(), pas.begin(), pas.end());

            } else {
                rs.emplace_back(string (1, arc.first));
            }

        }

    }

    return rs;
}

void PasswordManager::addCharToStartOfAllStrings(const char &pChar, std::vector<std::string> &pStrings) {
    for(std::string &s: pStrings)
        s = pChar + s;
}
