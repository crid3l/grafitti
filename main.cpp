#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <csignal>
#include <pwd.h>
#include <string>
#include <filesystem>
#include <cstring>
#include <unordered_set>
#include "config.h"
#include "mini/ini.h"
#include "setup.h"


namespace fs = std::filesystem;

void signalHandler(int signalNum) {
    if (signalNum == SIGTERM)
        exit(0);
}

std::unordered_set<std::string> daemonCommands{
        "-daemon", "-d"
};
std::unordered_set<std::string> setCommands{
        "-set", "-s"
};
std::unordered_set<std::string> helpCommands{
        "-help", "-h"
};

// Main daemon process
int main(int argc, char **argv) {

    std::string baseCommand;

    if (argc < 2) {
        baseCommand = "-daemon";
    } else {
        baseCommand = argv[1];
    }

    setupFirstTime();

    using namespace std;
    if (daemonCommands.count(baseCommand)) {
        cout << "Start Daemon" << endl;
        // Initialize the Daemon
//        initDaemon();
    } else if (setCommands.count(baseCommand)) {
        cout << "Set Variable " << endl;
    } else if (helpCommands.count(baseCommand)) {
        //TODO: Write usage string
    } else {
        cout << "Invalid command. Use \"-help\" for usage" << endl;
    }





    return 0;
}

