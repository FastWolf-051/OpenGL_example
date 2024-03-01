// contains all additional headers that needs to work
#include <code/UseHeaders.h>
// namespace for app
#include <code/Application.h>
// opengl fragment shader
#include <code/Shaders/GLSL_FragmentShader.h>
// opengl vertex shader
#include <code/Shaders/GLSL_VertexShader.h>
// my class console
#include <code/Console.hpp>

using namespace std;

int main() {
	// In begin,we set a color to background of console
	DebugCmd::SetBGColor(14);
	// Inittalize OpenGL
	glfwInit();
	// Use major version of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// Use minor version of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// Do this on Apple System
#if defined(__APPLE__)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// Creates a window instance
	GLFWwindow* Window = glfwCreateWindow(App::Win_Width, App::Win_Height, App::Win_Title, null, null);
	// When window not created
	if (Window == null) {
		// Show info
		DebugCmd::DisplayError("Failed to create OpenGL window");
		// Instantly close a window
		glfwTerminate();
		// Return error code
		return -1;
	}
	// When window created with no errors
	else {
		// Show info
		DebugCmd::DisplayLog("OpenGL window created");
	}
	// Focusing on our window
	glfwMakeContextCurrent(Window);
	// When GLAD not loaded
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		// Show info
		DebugCmd::DisplayError("GLAD initalize failed");
		return -1;
	}
	// When GLAD loaded
	else {
		// Show info 
		DebugCmd::DisplayLog("GLAD initalized");
	}
	// Set window viewport
	glViewport(null, null, App::Win_Width, App::Win_Height);
	// Set FramebufferSizeCallback
	// typecast because 2nf argument not compatable with OpenGl type
	glfwSetFramebufferSizeCallback(Window, (GLFWframebuffersizefun)App::framebuffer_size_callback);
	// Set icon for window
	GLFWimage image[1];
	// load image
	image[0].pixels = stbi_load("code/AppIcon/AppLogo2.png", &image[0].width, &image[0].height, 0, 4);
	// Set icon
	glfwSetWindowIcon(Window, 1, image);
	// Triangle coordinates
	float verticles[] = {
		/* POSITIONS */   /* Colors */
		// 1st point
		-0.5f,-0.5f,0.0f, 1.0f,1.0f,0.0f,
		// 2nd point
		0.5f,-0.5f,0.0f,  0.0f,1.0f,1.0f,
		// 3rd point
		0.0f,0.5f,0.0f,   1.0f,0.0f,1.0f
	};
	// VAO NEED TO BE BIND BEFORE VBO lol
	// vertex array object
	UnInt VAO;
	// generate array
	glGenVertexArrays(1, &VAO);
	// bind array
	glBindVertexArray(VAO);
	// Vertex Buffer Objects
	UnInt VBO;
	// generate Vertex buffer objects
	glGenBuffers(1, &VBO);
	// link buffer to chain
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// copy vertex data to buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticles), verticles, GL_STATIC_DRAW);
	// vertexShader
	UnInt vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Get shader source
	glShaderSource(vertexShader, 1, &vertexShaderSource, null);
	// compile shader
	glCompileShader(vertexShader);
	// Get errors
	// returns parameters from shader object
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &App::sucsess);
	// Log if anything is invaild
	if (!App::sucsess) {
		// gets info log from shader 
		glGetShaderInfoLog(vertexShader, 512, null, App::infoLog);
		DebugCmd::DisplayError("VertexShader compiling error");
	}
	// if no errors
	else{
		DebugCmd::DisplayLog("VertexShader compiled");
	}
	// fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// set shader source 
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, null);
	// compile shader
	glCompileShader(fragmentShader);
	// returns parameters from shader object
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &App::sucsess);
	// Log if anything is invaild
	if (!App::sucsess) {
		// gets info log from shader 
		glGetShaderInfoLog(fragmentShader, 512, null, App::infoLog);
		cout << "FragmentShader compiling error" << endl;
	}
	// if no errors
	else {
		cout << "FragmentShader compiled" << endl;
	}
	// create a shader program to joins 2 shaders
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	// attach 2 shaders to program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// link program
	glLinkProgram(shaderProgram);
	// use program
	glUseProgram(shaderProgram);
	// delete shaders after attaching it to the program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// set location and format of data of massive(verticles) universal attributes in index of index,which shiuld be used in rendering
	// (void*) - typecast to - pointer to void
	// void* uses when needs access to work with different poniters type in 1 code
	// stride = 3* sizeof(float)
	// 6*siezof(float) - takes 5,12,28,24 elements
	/* POSITION ATTRIBUTE */
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	// enable vertex attribute pointer
	glEnableVertexAttribArray(0);
	/* COLOR ATTRIBUTE */
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	// Main program loop
	while (!glfwWindowShouldClose(Window)) {
		// Set console title
		DebugCmd::CmdTitle("App Debug");
		// Use keyboard input
		App::processInput(Window);
		// Set color to window
		glClearColor(0.6f, 0.9f, 0.8f, 1.0f);
		// Clear window
		glClear(GL_COLOR_BUFFER_BIT);
		// draw triangle
		// use program
		glUseProgram(shaderProgram);
		// bind arrays
		glBindVertexArray(VAO);
		// draw it
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// change color buffer
		glfwSwapBuffers(Window);
		// if something events is running now
		glfwPollEvents();
	}
	// Info when window closed
	// delete all resources after close
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	cout << "Window closed";
	// When Program closes
	glfwTerminate();
	// Return default code
	return null;
}