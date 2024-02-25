#include <code/UseHeaders.h>
#include <code/Application.h>
#include <code/FragmentShader.h>
#include <code/VertexShader.h>

using namespace std;

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
#if defined(__APPLE__)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* Window = glfwCreateWindow(App::Win_Width, App::Win_Height, App::Win_Title, null, null);
	if (Window == null) {
		cout << "Failed to create OpenGL window" << endl;
		glfwTerminate();
		return -1;
	}
	else {
		cout << "OpenGL window created" << endl;
	}
	glfwMakeContextCurrent(Window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GLAD initalize failed" << endl;
		return -1;
	}
	else {
		cout << "GLAD initalized" << endl;
	}
	glViewport(null, null, App::Win_Width, App::Win_Height);
	glfwSetFramebufferSizeCallback(Window, (GLFWframebuffersizefun)App::framebuffer_size_callback);
	GLFWimage image[1];
	image[0].pixels = stbi_load("code/AppLogo2.png", &image[0].width, &image[0].height, 0, 4);
	glfwSetWindowIcon(Window, 1, image);
	float verticles[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, null);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &App::sucsess);
	if (!App::sucsess) {
		glGetShaderInfoLog(vertexShader, 512, null, App::infoLog);
		cout << "VertexShader compiling error" << endl;
	}
	else{
		cout << "VertexShader compiled" << endl;
	}
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, null);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &App::sucsess);
	if (!App::sucsess) {
		glGetShaderInfoLog(fragmentShader, 512, null, App::infoLog);
		cout << "FragmentShader compiling error" << endl;
	}
	else {
		cout << "FragmentShader compiled" << endl;
	}
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	while (!glfwWindowShouldClose(Window)) {
		App::CmdTitle("App debug");
		App::processInput(Window);
		glClearColor(0.3f, 0.5f, 0.8f, 1.0f);
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
	cout << "Window closed";
	glfwTerminate();
	return null;
}