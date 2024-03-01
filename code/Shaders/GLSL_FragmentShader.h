#if !defined(FragmentShader)
#define FragmentShader
#include <code/Shaders/GLSL.hpp>

GLSL_SCRIPT fragmentShaderSource =
GLSL_INIT_VERSION
GLSL_OUT_VECTOR4 "FragColor;" BR
GLSL_INPUT_VEC3 "OurColor;" BR
GLSL_EXECUTE_START
"   FragColor = vec4(OurColor,1.0f);" BR
GLSL_EXECUTE_END;
#endif