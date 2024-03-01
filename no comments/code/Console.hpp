#if !defined(Console)
#define Console
#include <code/UseHeaders.h>
#include <code/Application.h>
#define COL_RED  "\x1b[31m"
#define COL_GREEN "\x1b[32m"
#define COL_RESET "\x1b[0m"
class DebugCmd final {
private:
	enum ConsoleColors {
		ÑC_Black = 1,
		CC_White,
		CC_Cyan,
		CC_Magenta,
		CC_Gray,
		CC_Green,
		CC_Red,
		CC_Yellow,
		CC_Blue,
		CC_LightCyan,
		CC_LightMagenta,
		CC_LightYellow,
		CC_LightBlue,
		CC_LightGreen,
		CC_LightWhite,
		CC_LightRed
	};
public:
	static inline void  __fastcall CmdTitle(CharArray WinTitle) {
		SetConsoleTitleA(WinTitle);
	};
	static inline void DisplayLog(CharArray LogData) {
		cout << COL_GREEN << "[Log]: " << LogData << COL_RESET << endl;
	};
	static inline void DisplayError(CharArray Error) {
		cout << COL_RED << "[Error]: " << Error << COL_RESET << endl;
	}
	static inline void __stdcall SetBGColor(UnInt TColor) {
		switch (TColor) {
			case ÑC_Black: system("color 00"); break;
			case CC_White: system("color 70"); break;
			case CC_Cyan: system("color 30"); break;
			case CC_Magenta: system("color 50"); break;
			case CC_Gray: system("color 80"); break;
			case CC_Green: system("color 20"); break;
			case CC_Red: system("color 40"); break;
			case CC_Yellow: system("color 60"); break;
			case CC_Blue: system("color 10"); break;
			case CC_LightCyan: system("color b0"); break;
			case CC_LightMagenta: system("color d0"); break;
			case CC_LightYellow: system("color e0"); break;
			case CC_LightBlue: system("color 90"); break;
			case CC_LightGreen: system("color a0"); break;
			case CC_LightWhite: system("color f0"); break;
			case CC_LightRed: system("color c0"); break;
		}
	};
};
#endif