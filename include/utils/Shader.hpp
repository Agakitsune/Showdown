
#pragma once

#include "gl/Shader.hpp"

namespace showdown::utils {
    
    gl::Shader loadShader(const std::string& path, gl::ShaderType type);

} // namespace showdown::utils
