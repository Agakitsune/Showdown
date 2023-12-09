
#pragma once

#include "Utils.hpp"
#include "Type.hpp"

#include "utils/Chunk.hpp"

namespace showdown::gl {
    
    class Buffer {
        GLuint handle;
        BufferTarget _target;

        public:
            Buffer();
            Buffer(const Buffer&) = delete;
            Buffer(Buffer&&) noexcept;

            ~Buffer();

            Buffer& operator=(const Buffer&) = delete;
            Buffer& operator=(Buffer&&) noexcept;

            void bind(BufferTarget target) const;
            void target(BufferTarget target);

            void data(const void* data, size_t size, BufferUsage usage) const;

            template<typename T, size_t N>
            void data(const T (&data)[N], BufferUsage usage) const {
                this->data(data, sizeof(T) * N, usage);
            }

            void subData(const void* data, size_t size, size_t offset) const;

            template<size_t N, typename T>
            void subData(const T data[N], size_t offset) const {
                subData(data, sizeof(T) * N, offset);
            }

            utils::Chunk getData() const;
            utils::Chunk getSubData(size_t size, size_t offset) const;

            size_t size() const;
            BufferUsage usage() const;

            static void data(BufferTarget target, const void* data, size_t size, BufferUsage usage);

            template<size_t N, typename T>
            static void data(BufferTarget target, const T data[N], BufferUsage usage) {
                data(target, data, sizeof(T) * N, usage);
            }

            static void subData(BufferTarget target, const void* data, size_t size, size_t offset);

            template<size_t N, typename T>
            static void subData(BufferTarget target, const T data[N], size_t offset) {
                subData(target, data, sizeof(T) * N, offset);
            }
    };

} // namespace showdown::gl
