#include <stdlib.h>
#include <stdint.h>
#include <erron.h>
#include <base/StringExecute.h>


namespace itwbase
{

std::vector<std::string> StringExecute::splitStrITVec(const std::string &text, const std::string &separator)
{
	std::vector<std::string> vec;
	std::string str(text);
	std::string sep(separator);
	size_t n = 0, old = 0;
	while (n != std::string::npos)
	{
		n = str.find(sep, n);
		if (n != std::string::npos)
		{
			if (n != old)
			{
				vec.push_back(str.substr(old, n - old));
			}
			n += sep.length();
			old = n;
		}
	}
	if (old < str.length())
	{
		vec.push_back(str.substr(old, str.length() - old));
	}
	return vec;
}





}
