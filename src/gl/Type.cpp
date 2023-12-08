
#include "gl/Type.hpp"

namespace showdown::gl {

    std::ostream &operator<<(std::ostream &stream, const ShaderType type) {
        switch (type) {
            case ShaderType::Vertex:
                return stream << "Vertex";
            case ShaderType::TessControl:
                return stream << "Tessellation Control";
            case ShaderType::TessEvaluation:
                return stream << "Tessellation Evaluation";
            case ShaderType::Geometry:
                return stream << "Geometry";
            case ShaderType::Fragment:
                return stream << "Fragment";
            case ShaderType::Compute:
                return stream << "Compute";
            default:
                return stream;
        }
    }

}
