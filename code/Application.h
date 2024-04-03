#include <code/UseHeaders.h>
#if !defined(Application)
#define Application
#define null 0
#define AppWait cin.get
typedef unsigned int UnInt;
typedef const char* CharArray;
using namespace std;

namespace App {
	static void framebuffer_size_callback(GLFWwindow* window, __int16 width, __int16 height) {
		glViewport(null, null, width, height);
	}
	static void processInput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	};
	static const unsigned __int16 Win_Width = 400;
	static const unsigned __int16 Win_Height = 400;
	static const char* Win_Title = "OpenGL";
	__int32 sucsess;
	char infoLog[512];
}
#endif
