#if !defined(GLSL)
#define GLSL
#define BR "\n"
#define GLSL_INIT_VERSION "#version 330 core" BR
#define GLSL_SCRIPT const char*
#define GLSL_EXECUTE_START "void main(){" BR
#define GLSL_EXECUTE_END "}" BR
#define GLSL_OUT_VECTOR4 "out vec4 "
#define GLSL_OUT_VECTOR3 "out vec3 "
#define GLSL_LAYOUT_0_VEC3 "layout (location = 0) in vec3 "
#define GLSL_LAYOUT_1_VEC3 "layout (location = 1) in vec3 "
#define GLSL_INPUT_VEC3 "in vec3 "
#endif