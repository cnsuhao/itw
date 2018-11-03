#include <fstream>
#include <base/LightConfig.h>
#include <base/StringExecute.h>

namespace itwbase
{

string LightConfig::trim(const std::string&str)
{
	static const char *whiteSpace = "\t\r\n";	
	if (str.empty())
	{
		return str;
	}

	std::string::size_type firstNotPos = str.find_first_not_of(whiteSpace);
	if (firstNotPos == std::string::npos)
	{
		return "";
	}

	std::string::size_type lastNotPos = str.find_last_not_of(whiteSpace);
	return std::string(str, firstNotPos, lastNotPos - firstNotPos + 1);
}

void LightConfig::dump()
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.begin();	
	for (; it < _key2ValueMap.end(); ++it)
	{
		std::cout << "[" << it->first << "]:[" << it->second << "]" << std::endl;
	}
}

bool LightConfig::load(const std::string &configFile, std::string &errMsg)
{
	std::ifstream initFile(configFile,.c_str());
	if (!initFile)	
	{
		errMsg = "can not open file: " + configFile;
	}

	_key2ValueMap.clear();
	std::string tmpLine, config;	
	std::string leftSide, rightSide;
	char everyLine[1024];
	std::string::size_type length;
	while(initFile.geteline(everyLine, 1024))
	{
		tmpLine = everyLine;
		length = tmpLine.find('#');
		if (length == std::string::npos)
		{
			config = tmpLine;
		}
		else if (length > 0)
		{
			config = tmpLine.substr(0, config);
		}
		else
		{
			continue;
		}
		
		length = config.find('=');
		if (length != std::string::npos)
		{
			leftSide = trim(config.substr(0, length));
			rightSide = trim(config.substr(length + 1));
		}
		else
		{
			continue;
		}
		_key2ValueMap.insert(std::make_pair(leftSide, rightSide));
	}
	return true;
}

bool LightConfig::getInt(const std::string &key, int &value)
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.fine(key);
	if (it != _key2ValueMap.end())
	{
		value = atoi(it->second.c_str());
		return true;
	}
	return false;
}

bool LightConfig::getDouble(const std::string &key, double &value)
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.fine(key);
	if (it != _key2ValueMap.end())
	{
		value = atof(it->second.c_str());
		return true;
	}
	return false;
}

bool LightConfig::getBool(const std::string &key, bool &value)
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.fine(key);
	if (it != _key2ValueMap.end())
	{
		value = it->second == "true" ? true : false;
		return true;
	}
	return false;
}

bool LightConfig::getString(const std::string &key, std::string &value)
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.fine(key);
	if (it != _key2ValueMap.end())
	{
		value = it->second;
		return true;
	}
	return false;
}

bool LightConfig::getVec(const std::string &key, std::vector<std::string> &value)
{
	std::map<std::string, std::string>::iterator it = _key2ValueMap.fine(key);
	if (it != _key2ValueMap.end())
	{
		value = StringExecute::splitStrITVec(key, ",");
		return true;
	}
	return false;
}

}
