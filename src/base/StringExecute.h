#ifndef _ITW_BASE_STRINGEXECUTE_
#define _ITW_BASE_STRINGEXECUTE_

#include <vector>
#include <string>

namespace itwbase
{

class StringExecute
{
public:
	static std::vector<std::string> splitStrITVec(const std::string &text, const std::string &separator);

};

}
#endif
