#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>

class FileManager
{

public:

    static bool Unzip(const char* password) {

        // build command
        std::string command =  "unzip -P ";
        command.append(password);
        command.append(R"( ../resources/caso\ 7\ test_legacy\ encryption.zip -d ../resources)");

        // execute command and open stream with output
        FILE* pipe = popen(command.c_str(), "r");

        if (!pipe) throw std::runtime_error("popen() failed!");

        char buffer[128];
        std::string result;

        // read output
        try {

            while (fgets(buffer, sizeof buffer, pipe) != nullptr)
                result += buffer;

        } catch (...) {
            pclose(pipe);
            throw;
        }

        pclose(pipe);

        // use output to know if the password was correct or not

        if( result.length() == 57 )  // error message, didn't work
            return false;
        else // 101
            return true;

    }

};
