
#include <FileManager.h>

int main() {

    bool rs = FileManager::Unzip("2AK");

    if(rs)
        std::cout << "password was correct" << std::endl;
    else
        std::cout << "password was incorrect" << std::endl;

    return 0;
}