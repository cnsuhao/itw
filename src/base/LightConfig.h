#ifndef _ITW_BASE_LIGHTCONFIG_
#define _ITW_BASE_LIGHTCONFIG_

#include<string>
#include<map>
#include<set>
#include<iostream>

namespace itwbase
{
class LightConfig
{
public:
	LightConfig(){}
	~LightConfig(){}

	std::string trim(const std::string&s);
	void dump();
	bool load(const std::string &configFile, std::string &errMsg);
	bool getInt(const std::string &key, int &value);
	bool getDouble(const std::string &key, double &value);
	bool getBool(const std::string &key, bool &value);
	bool getString(const std::string &key, std::string &value);
	bool getVec(const std::string &key, std::vector<std::string> &value);
private:
	std::map<std::string, std::string> _key2ValueMap;
};

}
#endif
