#if !defined(FragmentShader)
#define FragmentShader
#include <code/Shaders/GLSL.hpp>

GLSL_SCRIPT fragmentShaderSource =
GLSL_INIT_VERSION
GLSL_OUT_VECTOR4 "FragColor;" BR
GLSL_EXECUTE_START
"   FragColor = vec4(0.3f, 0.9f, 0.4f, 0.3f);" BR
GLSL_EXECUTE_END;
#endif