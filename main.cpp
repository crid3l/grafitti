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


void createAppDirectory();

namespace fs = std::filesystem;
using namespace std;

void signalHandler(int signalNum) {
    if (signalNum == SIGTERM)
        exit(0);
}

// Function to initialize the daemon
void initDaemon() {

}

unordered_set<string> daemonCommands{
        "-daemon", "-d"
};
unordered_set<string> setCommands{
        "-set", "-s"
};
unordered_set<string> helpCommands{
        "-help", "-h"
};

// Main daemon process
int main(int argc, char **argv) {

    string baseCommand;

    if (argc < 2) {
        baseCommand = "-daemon";
    } else {
        baseCommand = argv[1];
    }

    createAppDirectory();

    if (daemonCommands.count(baseCommand)) {
        cout << "Start Daemon" << endl;
        // Initialize the Daemon
        initDaemon();
    } else if (setCommands.count(baseCommand)) {
        cout << "Set Variable " << endl;
    } else if (helpCommands.count(baseCommand)) {
        //TODO: Write usage string
    } else {
        cout << "Invalid command. Use \"-help\" for usage" << endl;
    }





    return 0;
}

void createAppDirectory() {
    std::string str;
    if ((str = getenv("HOME")).empty()) {
        str = getpwuid(getuid())->pw_dir;
    }
    str.append("/.").append(APP_NAME);
    fs::create_directories(str);
}
