#include <NodeInitializer.h>
#include <PasswordManager.h>
#include <ProbabilisticCracker.h>
#include <PasswordCracker.h>


using namespace std;

int main() {

    srand (time(nullptr));

    // generate all posible passwords
    PasswordManager passwordManager;

    { // create cube && passwords
        NodeInitializer initializer;
        std::vector<Node*> nodes = initializer.createNodes();
        initializer.linkNodes(nodes);

        passwordManager.generatePasswords(nodes);
    }

    ProbabilisticCracker probabilisticCracker(passwordManager);
    probabilisticCracker.crack();

    return 0;
}