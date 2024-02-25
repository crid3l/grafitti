//
// Created by kp2 on 2/25/24.
//

#ifndef KDE_GRAFFITI_SETUP_H
#define KDE_GRAFFITI_SETUP_H

#include "mini/ini.h"
#include "config.h"
#include <unordered_set>
#include <cstring>
#include <filesystem>
#include <string>
#include <pwd.h>
#include <csignal>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;
/**
 * Create the App Directory if it doesn't exist
 * @return st
 */
std::string createAppDirectory();

/**
 * Setup config directory in-case it hasn't been before.
 * The daemon will be watching this file
 * @param directoryPath
 */
void initConfigDirectory(const std::string& directoryPath);

/**
 * Runner function to guide initialization
 */
void setupFirstTime();

/**
 * Create directories at the home directory
 * @return str: directory string
 */
std::string createAppDirectory() {
    std::string str;
    if ((str = getenv("HOME")).empty()) {
        str = getpwuid(getuid())->pw_dir;
    }
    str.append("/.config/").append(APP_NAME);
    if(!fs::exists(str)) {
        fs::create_directories(str);
    }
    initConfigDirectory(str);
    return str;
}

/**
 * Set up the config directory with an initial file.
 * Ideally this should actually be a bash script :P
 * @param directoryPath
 */
void initConfigDirectory(const std::string& directoryPath) {
    std::string configPath = directoryPath + "/" + "config.ini";

    // breakout if already initialized.
    if(fs::exists(configPath)) {
        return;
    }


}

/**
 * First create app directory, if not exists
 * Then setup ini file, if not exists
 */
void setupFirstTime() {
    std::string appDirectory = createAppDirectory();
    initConfigDirectory(appDirectory);
}

#endif //KDE_GRAFFITI_SETUP_H
