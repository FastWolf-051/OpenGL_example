#if !defined(Console)
#define Console
#include <code/UseHeaders.h>
// for use CharArray
#include <code/Application.h>
// ANSI RED TEXT CODE
#define COL_RED  "\x1b[31m"
// ANSI GREEN TEXT CODE
#define COL_GREEN "\x1b[32m"
// ANSI TEXT COLOR RESET
#define COL_RESET "\x1b[0m"
// Class debug cmd - for debug of a project
class DebugCmd final {
private:
	enum ConsoleColors {
		// CC - console color
		/* Default colors */
		ÑC_Black = 1,
		CC_White, // 2
		/* Colored */
		CC_Cyan, // (analog = Aqua) 3
		CC_Magenta, // (analog = Purple) 4
		CC_Gray, // 5
		CC_Green, // 6
		CC_Red, // 7
		CC_Yellow, // 8
		CC_Blue, // 9
		/* Light colored */
		CC_LightCyan, // 10
		CC_LightMagenta, // 11
		CC_LightYellow, // 12
		CC_LightBlue, // 13
		CC_LightGreen, // 14
		CC_LightWhite, // 15
		CC_LightRed // 16
	};
public:
	// Set Cmd Title
	static inline void  __fastcall CmdTitle(CharArray WinTitle) {
		// Windows.h function
		SetConsoleTitleA(WinTitle);
	};
	// display a log
	static inline void DisplayLog(CharArray LogData) {
		cout << COL_GREEN << "[Log]: " << LogData << COL_RESET << endl;
	};
	// display a error
	static inline void DisplayError(CharArray Error) {
		cout << COL_RED << "[Error]: " << Error << COL_RESET << endl;
	}
	// Set text console color
	static inline void __stdcall SetBGColor(UnInt TColor) {
		// check for argument lol
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
#endif // Console