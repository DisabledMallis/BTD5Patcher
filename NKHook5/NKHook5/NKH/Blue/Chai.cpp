#include "pch.h"
#include "Chai.h"
#include "../Patches/FlagHacker.h"
#include <filesystem>

/*
Chai format funcs
*/
void injectFlag(const string& name, int flag) {
	string* str = new string(name.c_str());
	FlagHacker::addHackedFlag(str, flag);
}

/*
Setup
*/

using namespace chaiscript;
namespace fs = std::filesystem;

ChaiScript* chai;

void runChaiFile(string path) {
	chai->eval_file(path);
}

void Chai::startChai()
{
	chai = new ChaiScript();

	chai->add(fun(&injectFlag), "injectFlag");

	string appdata = string(getenv("APPDATA"));
	string nkhookdir = appdata.append("/NKHook5");
	string pluginDir = nkhookdir.append("/Plugins");
	std::string ext(".chai");
	for (auto& p : fs::recursive_directory_iterator(pluginDir.c_str()))
	{
		if (p.path().extension() == ext) {
			new thread(runChaiFile, p.path().u8string());
		}
	}
}