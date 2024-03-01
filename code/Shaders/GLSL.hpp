#if !defined(GLSL)
#define GLSL
// line break
#define BR "\n"
// initalize GLSL version
#define GLSL_INIT_VERSION "#version 330 core" BR
// GLSL script
#define GLSL_SCRIPT const char*
// main function start
#define GLSL_EXECUTE_START "void main(){" BR
// main function end
#define GLSL_EXECUTE_END "}" BR
// out vec4
#define GLSL_OUT_VECTOR4 "out vec4 "
// layout(location = 0) in vec3
#define GLSL_LAYOUT_0_VEC3 "layout (location = 0) in vec3 "
#endif