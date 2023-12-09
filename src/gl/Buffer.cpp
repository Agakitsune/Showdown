
#include "gl/Buffer.hpp"

namespace showdown::gl {

    Buffer::Buffer() {
        glGenBuffers(1, &handle);
    }

    Buffer::Buffer(Buffer&& other) noexcept {
        handle = other.handle;
        other.handle = 0;
    }

    Buffer::~Buffer() {
        glDeleteBuffers(1, &handle);
    }

    Buffer& Buffer::operator=(Buffer&& other) noexcept {
        handle = other.handle;
        other.handle = 0;
        return *this;
    }

    void Buffer::bind(BufferTarget target) const {
        glBindBuffer(static_cast<GLenum>(target), handle);
    }

    void Buffer::target(BufferTarget target) {
        this->_target = target;
    }

    void Buffer::data(const void* data, size_t size, BufferUsage usage) const {
        glBufferData(static_cast<GLenum>(_target), size, data, static_cast<GLenum>(usage));
    }

    void Buffer::subData(const void* data, size_t size, size_t offset) const {
        glBufferSubData(static_cast<GLenum>(_target), offset, size, data);
    }

    utils::Chunk Buffer::getData() const {
        return getSubData(size(), 0);
    }

    utils::Chunk Buffer::getSubData(size_t size, size_t offset) const {
        utils::Chunk data(size);
        glGetBufferSubData(static_cast<GLenum>(_target), offset, size, data.data());
        return data;
    }

    size_t Buffer::size() const {
        GLint size;
        glGetBufferParameteriv(static_cast<GLenum>(_target), GL_BUFFER_SIZE, &size);
        return size;
    }

    BufferUsage Buffer::usage() const {
        GLint usage;
        glGetBufferParameteriv(static_cast<GLenum>(_target), GL_BUFFER_USAGE, &usage);
        return static_cast<BufferUsage>(usage);
    }

    void Buffer::data(BufferTarget target, const void* data, size_t size, BufferUsage usage) {
        glBufferData(static_cast<GLenum>(target), size, data, static_cast<GLenum>(usage));
    }

    void Buffer::subData(BufferTarget target, const void* data, size_t size, size_t offset) {
        glBufferSubData(static_cast<GLenum>(target), offset, size, data);
    }

} // namespace showdown::gl
