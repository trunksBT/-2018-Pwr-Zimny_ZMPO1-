#include <string>

namespace reqNumOfArgsFor
{
	constexpr int CREATE_MENU = 3;
	constexpr int SELECT = 2;
}

namespace defaultVals
{
	static const int ZERO = 0;
	static const std::string DEFAULT_STRING_VAL = "DEFAULT_STRING_VAL";
	static const std::string CURSOR_SIGN = ":- ";
	static const char* SEPARATOR = " ";  // wskaznik na tablice znakow
	static const char* END_LINE = "\n";
}

namespace idxForInput
{
	static const int MENU_NAME = 1;
}

namespace actions
{
	static const std::string BACK = "back";
	static const std::string CREATE_MENU = "createMenu";
	static const std::string CREATE_COMMAND = "createCommand";
	static const std::string DELETE = "delete";
	static const std::string SELECT = "select";
	static const std::string PRINT = "print";
	static const std::string HELP = "help";
}

namespace funs
{
	void actionHelp();
}
