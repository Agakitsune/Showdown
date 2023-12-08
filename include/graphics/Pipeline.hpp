
#pragma once

#include <unordered_map>

#include "gl/Program.hpp"
#include "utils/Program.hpp"

namespace showdown::graphics {

    class Pipeline {
        gl::Program _program;

        public:
            Pipeline(const std::string &vertexPath, const std::string &fragmentPath);
            Pipeline(const std::string &vertexPath, const std::string &geometryPath, const std::string &fragmentPath);
            Pipeline(const gl::Program &program);
            Pipeline(gl::Program &&program);
            Pipeline(const Pipeline &other) = default;
            Pipeline(Pipeline &&other) noexcept = default;

            virtual ~Pipeline() = default;

            virtual void setup() const;
            virtual void reset() const;

            void set(const std::string &uniform, GLfloat v0) const;
            void set(const std::string &uniform, GLfloat v0, GLfloat v1) const;
            void set(const std::string &uniform, GLfloat v0, GLfloat v1, GLfloat v2) const;
            void set(const std::string &uniform, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const;
            
            void set(const std::string &uniform, GLint v0) const;
            void set(const std::string &uniform, GLint v0, GLint v1) const;
            void set(const std::string &uniform, GLint v0, GLint v1, GLint v2) const;
            void set(const std::string &uniform, GLint v0, GLint v1, GLint v2, GLint v3) const;
            
            void set(const std::string &uniform, GLuint v0) const;
            void set(const std::string &uniform, GLuint v0, GLuint v1) const;
            void set(const std::string &uniform, GLuint v0, GLuint v1, GLuint v2) const;
            void set(const std::string &uniform, GLuint v0, GLuint v1, GLuint v2, GLuint v3) const;
            
            void set(const std::string &uniform, GLsizei count, GLfloat *value) const;
            void set(const std::string &uniform, GLsizei count, GLint *value) const;
            void set(const std::string &uniform, GLsizei count, GLuint *value) const;
            
            template<size_t N, typename T>
            requires std::is_integral_v<T> && std::is_signed_v<T>
            void set(const std::string &uniform, const math::vector<N, T> &vector) const {
                set(uniform, N, vector.data());
            }

            template<size_t N, typename T>
            requires std::is_integral_v<T> && std::negation_v<std::is_signed<T>>
            void set(const std::string &uniform, const math::vector<N, T> &vector) const {
                set(uniform, N, vector.data());
            }

            template<size_t N, typename T>
            requires std::is_floating_point_v<T>
            void set(const std::string &uniform, const math::vector<N, T> &vector) const {
                set(uniform, N, vector.data());
            }

            void set2x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set3x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            
            void set2x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set3x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            
            void set2x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x2(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            
            void set3x4(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x3(const std::string &uniform, GLsizei count, GLboolean transpose, GLfloat *value) const;
    };

}
