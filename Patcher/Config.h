#ifndef PATCHER_CONFIG
#define PATCHER_CONFIG

#include <nlohmann/json.hpp>

class Config : public nlohmann::json {
	static inline Config* instance;
	static void createConfig();
	static bool fileExists();
public:
	static auto getConfig() -> Config&;
};

#endif /* PATCHER_CONFIG */
