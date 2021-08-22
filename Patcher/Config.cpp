#include "Config.h"

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>
#include <filesystem>

void Config::createConfig() {
	std::ofstream configFile("config.json");
	Config conf;
	conf["patch"] = true;
	conf["profile"] = "Default Profile";
	conf["remove_fps_cap"] = true;
	configFile << std::setw(4) << conf;
	configFile.flush();
	configFile.close();
}

bool Config::fileExists() {
	std::filesystem::path configPath{"config.json"};
	return std::filesystem::exists(configPath);
}

auto Config::getConfig() -> Config& {
	if(instance) {
		return *instance;
	}

	instance = new Config();

	if(!fileExists()) {
		createConfig();
	}

	std::ifstream configFile("config.json");
	configFile >> *instance;
	configFile.close();

	return *instance;
}