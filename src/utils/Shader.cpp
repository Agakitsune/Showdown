
#include "utils/Shader.hpp"

#include <fstream>

#ifdef SHOWDOWN_DEBUG
    #include "utils/Debug.hpp"
#endif

namespace showdown::utils {
    
    gl::Shader loadShader(const std::string &path, gl::ShaderType type) {
        std::ifstream file(path);

        #ifdef SHOWDOWN_DEBUG
            debug("Shader") << "Loading " << type << " shader: " << path << std::endl;
        #endif

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + path);
        }
        std::string source;
        std::string line;
        while (std::getline(file, line)) {
            source += line + '\n';
        }
        gl::Shader shader(type);
        shader.source(source);
        if (!shader.compile())
            throw std::runtime_error("Could not compile shader: " + shader.getInfoLog());
        return shader;
    }

} // namespace showdown::utils
