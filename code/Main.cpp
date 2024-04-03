#include <code/UseHeaders.h>
#include <code/Application.h>
#include <code/Shaders/GLSL_FragmentShader.h>
#include <code/Shaders/GLSL_VertexShader.h>
#include <code/Console.hpp>

using namespace std;

int main(const int argc,const char* argv[]) {
	DebugCmd::SetBGColor(2);
	DebugCmd::GetAppPath(argv[0]);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
#if defined(__APPLE__)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* Window = glfwCreateWindow(App::Win_Width, App::Win_Height, App::Win_Title, null, null);
	if (Window == null) {
		DebugCmd::DisplayError("Failed to create OpenGL window");
		glfwTerminate();
		return -1;
	}
	else {
		DebugCmd::DisplayLog("OpenGL window created");
	}
	glfwMakeContextCurrent(Window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		DebugCmd::DisplayError("GLAD initalize failed");
		return -1;
	}
	else {
		DebugCmd::DisplayLog("GLAD initalized");
	}
	glViewport(null, null, App::Win_Width, App::Win_Height);
	glfwSetFramebufferSizeCallback(Window, (GLFWframebuffersizefun)App::framebuffer_size_callback);
	GLFWimage image[1];
	image[0].pixels = stbi_load("code/AppIcon/AppLogo2.png", &image[0].width, &image[0].height, 0, 4);
	glfwSetWindowIcon(Window, 1, image);
	float verticles[] = {
		-0.5f,-0.5f,0.0f, 1.0f,1.0f,0.0f,
		0.5f,-0.5f,0.0f,  0.0f,1.0f,1.0f,
		0.0f,0.5f,0.0f,   1.0f,0.0f,1.0f
	};
	UnInt VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	UnInt VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);
	UnInt vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, null);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &App::sucsess);
	if (!App::sucsess) {
		glGetShaderInfoLog(vertexShader, 512, null, App::infoLog);
		DebugCmd::DisplayError("VertexShader compiling error");
	}
	else{
		DebugCmd::DisplayLog("VertexShader compiled");
	}
	UnInt fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, null);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &App::sucsess);
	if (!App::sucsess) {
		glGetShaderInfoLog(fragmentShader, 512, null, App::infoLog);
		DebugCmd::DisplayError("FragmentShader compiling error");
	}
	else {
		DebugCmd::DisplayLog("FragmentShader compiled");
	}
	UnInt shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	while (!glfwWindowShouldClose(Window)) {
		DebugCmd::CmdTitle("App Debug");
		App::processInput(Window);
		glClearColor(0.9f, 0.7f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(Window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	DebugCmd::DisplayLog("Window closed");
	glfwTerminate();
	AppWait();
	return null;
}