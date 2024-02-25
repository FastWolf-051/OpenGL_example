#if !defined(FragmentShader)
#define FragmentShader

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.3f, 0.9f, 0.4f, 0.3f);\n"
"}\0";
#endif
