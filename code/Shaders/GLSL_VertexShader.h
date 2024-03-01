#if !defined(VertexShader)
#define VertexShader
#include <code/Shaders/GLSL.hpp>

GLSL_SCRIPT vertexShaderSource =
GLSL_INIT_VERSION
GLSL_LAYOUT_0_VEC3 "aPos;" BR
GLSL_LAYOUT_1_VEC3 "aColor;" BR
GLSL_OUT_VECTOR3 "OurColor;" BR
GLSL_EXECUTE_START
"   gl_Position = vec4(aPos,1.0f);" BR
"	OurColor = aColor;" BR
GLSL_EXECUTE_END;
#endif