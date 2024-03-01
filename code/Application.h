#include <code/UseHeaders.h>
#if !defined(Application)
#define Application
// User-define
#define null 0
// user typedef
typedef unsigned int UnInt;
// For not see C2065 errors
using namespace std;
namespace App {
	// When user resizes a window,glViewport needs to be change to window size
	static void framebuffer_size_callback(GLFWwindow* window, __int16 width, __int16 height) {
		// Set glViewport same as window width and height
		glViewport(null, null, width, height);
	}
	// Use keyboard input
	static void processInput(GLFWwindow* window) {
		// When "ESC" key pressed
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			// Close the window
			glfwSetWindowShouldClose(window, true);
		}
	};
	// Change console title
	static void __fastcall CmdTitle(const char* title) {
		// Windows.h function
		SetConsoleTitleA(title);
	};
	// Window height
	static const unsigned __int16 Win_Width = 400;
	// Window width
	static const unsigned __int16 Win_Height = 400;
	// Window title
	static const char Win_Title[7] = "maybe?";
	// Sucess code
	__int32 sucsess;
	// Log data
	char infoLog[512];
}
#endif
