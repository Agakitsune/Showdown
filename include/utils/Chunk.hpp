
#pragma once

#include <cstddef>

namespace showdown::utils {

    class Chunk {
        char *_data;
        size_t _refCount;

        public:
            Chunk(size_t size);
            Chunk(const Chunk &other);
            Chunk(Chunk &&other) noexcept;
            ~Chunk();

            Chunk &operator=(const Chunk &other);
            Chunk &operator=(Chunk &&other) noexcept;

            void *data() const;

            operator void *() const;
    };

}
