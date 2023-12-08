
#include "utils/Chunk.hpp"

namespace showdown::utils {

    Chunk::Chunk(size_t size) : _data(new char[size]), _refCount(1) {}

    Chunk::Chunk(const Chunk &other) : _data(other._data), _refCount(other._refCount) {
        ++_refCount;
    }

    Chunk::Chunk(Chunk &&other) noexcept : _data(other._data), _refCount(other._refCount) {
        other._data = nullptr;
        other._refCount = 0;
    }

    Chunk::~Chunk() {
        if (_refCount == 1) {
            delete _data;
        } else {
            --_refCount;
        }
    }

    Chunk &Chunk::operator=(const Chunk &other) {
        _data = other._data;
        _refCount = other._refCount;
        ++_refCount;
        return *this;
    }

    Chunk &Chunk::operator=(Chunk &&other) noexcept {
        _data = other._data;
        _refCount = other._refCount;
        other._data = nullptr;
        other._refCount = 0;
        return *this;
    }

    void *Chunk::data() const {
        return _data;
    }

    Chunk::operator void *() const {
        return _data;
    }

}
