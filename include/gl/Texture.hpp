
#pragma once

#include <string>

#include "Utils.hpp"
#include "Type.hpp"
#include "math/math.hpp"

namespace showdown::gl {

    class Texture {
        size_t *refCount;
        GLuint handle;
        TextureTarget target;

        public:
            Texture();
            Texture(const Texture &other);
            Texture(Texture &&other);

            ~Texture();

            Texture &operator=(const Texture &other);
            Texture &operator=(Texture &&other);

            void bind(gl::TextureTarget target);

            void data1D(GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;
            void data2D(GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, GLsizei height, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;
            void data3D(GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, GLsizei height, GLsizei depth, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;

            void subdata1D(GLint level, GLint xoffset, GLsizei width, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;
            void subdata2D(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;
            void subdata3D(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, gl::TextureFormat format, gl::TextureDataType type, const void *data) const;

            static void data1D(gl::TextureTarget target, GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, gl::TextureFormat format, gl::TextureDataType type, const void *data);
            static void data2D(gl::TextureTarget target, GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, GLsizei height, gl::TextureFormat format, gl::TextureDataType type, const void *data);
            static void data3D(gl::TextureTarget target, GLint level, gl::TextureInternalFormat internalFormat, GLsizei width, GLsizei height, GLsizei depth, gl::TextureFormat format, gl::TextureDataType type, const void *data);

            static void subdata1D(gl::TextureTarget target, GLint level, GLint xoffset, GLsizei width, gl::TextureFormat format, gl::TextureDataType type, const void *data);
            static void subdata2D(gl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, gl::TextureFormat format, gl::TextureDataType type, const void *data);
            static void subdata3D(gl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, gl::TextureFormat format, gl::TextureDataType type, const void *data);

            void setTextureParameter(gl::TextureParameterName name, GLfloat value) const;
            void setTextureParameter(gl::TextureParameterName name, GLint value) const;
            void setTextureParameter(gl::TextureParameterName name, GLfloat *value) const;
            void setTextureParameter(gl::TextureParameterName name, GLint *value) const;
            void setTextureParameter(gl::TextureParameterName name, GLuint *value) const;
            void setTextureParameter(gl::TextureParameterName name, gl::TextureWrap value) const;
            void setTextureParameter(gl::TextureParameterName name, gl::TextureFilter value) const;

            void generateMipmap() const;

            void activate(size_t unit) const;

            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, GLfloat value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, GLint value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, GLfloat *value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, GLint *value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, GLuint *value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, gl::TextureWrap value);
            static void setTextureParameter(gl::TextureTarget target, gl::TextureParameterName name, gl::TextureFilter value);

            static void generateMipmap(gl::TextureTarget target);

            math::vec2u size() const;
    };

}