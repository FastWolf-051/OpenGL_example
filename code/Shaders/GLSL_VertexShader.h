#if !defined(VertexShader)
#define VertexShader
#include <code/Shaders/GLSL.hpp>

GLSL_SCRIPT vertexShaderSource =
GLSL_INIT_VERSION
GLSL_LAYOUT_0_VEC3 "aPos;" BR
GLSL_EXECUTE_START
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);" BR
GLSL_EXECUTE_END;
#endif