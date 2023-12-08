
#pragma once

#include "gl/Utils.hpp"

#include "math/math.hpp"

namespace showdown::gl {
    
    class Uniform {
        GLint location;

        public:
            Uniform(GLint location);
            Uniform(const Uniform&);
            Uniform(Uniform&&) noexcept;

            ~Uniform() = default;

            Uniform& operator=(const Uniform&);
            Uniform& operator=(Uniform&&) noexcept;

            bool isValid() const;

            void set(GLfloat v0) const;
            void set(GLfloat v0, GLfloat v1) const;
            void set(GLfloat v0, GLfloat v1, GLfloat v2) const;
            void set(GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) const;
            
            void set(GLint v0) const;
            void set(GLint v0, GLint v1) const;
            void set(GLint v0, GLint v1, GLint v2) const;
            void set(GLint v0, GLint v1, GLint v2, GLint v3) const;
            
            void set(GLuint v0) const;
            void set(GLuint v0, GLuint v1) const;
            void set(GLuint v0, GLuint v1, GLuint v2) const;
            void set(GLuint v0, GLuint v1, GLuint v2, GLuint v3) const;

            void set(GLsizei count, GLfloat *value) const;
            void set(GLsizei count, GLint *value) const;
            void set(GLsizei count, GLuint *value) const;

            template<size_t N, typename T>
            requires std::is_integral_v<T> && std::is_signed_v<T>
            void set(const math::vector<N, T> &vector) const {
                set(N, vector.data());
            }

            template<size_t N, typename T>
            requires std::is_integral_v<T> && std::negation_v<std::is_signed<T>>
            void set(const math::vector<N, T> &vector) const {
                set(N, vector.data());
            }

            template<size_t N, typename T>
            requires std::is_floating_point_v<T>
            void set(const math::vector<N, T> &vector) const {
                set(N, vector.data());
            }

            void set2x2(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set3x3(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x4(GLsizei count, GLboolean transpose, GLfloat *value) const;

            void set2x3(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set3x2(GLsizei count, GLboolean transpose, GLfloat *value) const;

            void set2x4(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x2(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set3x4(GLsizei count, GLboolean transpose, GLfloat *value) const;
            void set4x3(GLsizei count, GLboolean transpose, GLfloat *value) const;
    };

} // namespace showdown::gl
