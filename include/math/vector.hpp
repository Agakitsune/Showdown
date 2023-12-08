
#pragma once

#include <cstddef>
#include <cstring>
#include <stdexcept>
#include <type_traits>

#ifdef SHOWDOWN_EXPERIMENTAL
    #include <experimental/simd>
#endif

#include <cmath>
#include <cstring>

#include "vectormeta.hpp"

namespace showdown::math {
    
    template<size_t N, typename T>
    requires std::is_arithmetic_v<T>
    class vector {
        T _data[N];

        template<typename Ts>
        constexpr void _set(size_t offset, Ts v) {
            _data[offset] = static_cast<T>(v);
        }

        template<size_t M, typename Ts>
        constexpr void _set(size_t offset, const vector<M, Ts> &v) {
            const Ts *data = v.data();
            for (size_t i = 0; i < M; ++i) {
                _data[offset + i] = static_cast<T>(data[i]);
            }
        }

        constexpr void _set(size_t offset, T v) {
            _data[offset] = v;
        }

        #ifdef SHOWDOWN_EXPERIMENTAL
            template<typename U, size_t... M>
            requires (sizeof...(M) == N)
            constexpr void _set(const std::experimental::fixed_size_simd<U, N> &simd, std::index_sequence<M...>) {
                (
                    (this->_data[M] = static_cast<T>(simd[M])),
                    ...
                );
            }
        #endif

        public:
            using type = T;

            constexpr size_t size() const {
                return N;
            }

            constexpr vector() = default;

            // Copy&move constructors

            constexpr vector(const vector<N, T> &other) = default;
            constexpr vector(vector<N, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            constexpr vector(const vector<N, U> &other) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = static_cast<T>(other._data[i]);
                }
            }

            template<typename U>
            constexpr vector(vector<N, U> &&other) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = static_cast<T>(other._data[i]);
                }
            }

            // Scalar constructor

            explicit constexpr vector(T x) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = x;
                }
            }

            template<typename... Vs>
            requires (_meta::argumentSize<std::remove_cvref_t<Vs>...>::value == N)
            explicit constexpr vector(Vs&&... v) {
                size_t off = 0;
                ([&] {
                    _set(off, std::forward<Vs>(v));
                    off += _meta::argumentSize<std::remove_cvref_t<Vs>>::value;
                }(), ...);
            }

            // Conversions from other vector types

            template<size_t M, typename U>
            requires (M > N)
            explicit constexpr vector(const vector<M, U> &other) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = static_cast<T>(other._data[i]);
                }
            }

            // Assignments

            constexpr vector<N, T> &operator=(const vector<N, T> &other) = default;
            constexpr vector<N, T> &operator=(vector<N, T> &&other) = default;

            template<typename U>
            constexpr vector<N, T> &operator=(const vector<N, U> &other) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = static_cast<T>(other._data[i]);
                }
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator=(vector<N, U> &&other) {
                for (size_t i = 0; i < N; ++i) {
                    _data[i] = static_cast<T>(other._data[i]);
                }
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            constexpr vector<N, T> &operator+=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMNETAL
                    std::experimental::fixed_size_simd<U, N> a([this](int i) { return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a += b;
                    _set(a, std::make_index_sequence<N>{});
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] += scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator-=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMNETAL
                    std::experimental::fixed_size_simd<U, N> a([this](int i) { return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a -= b;
                    _set(a, std::make_index_sequence<N>{});
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] -= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator*=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMNETAL
                    std::experimental::fixed_size_simd<U, N> a([this](int i) { return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a *= b;
                    _set(a, std::make_index_sequence<N>{});
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] *= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator/=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMNETAL
                    std::experimental::fixed_size_simd<U, N> a([this](int i) { return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a /= b;
                    _set(a, std::make_index_sequence<N>{});
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] /= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator%=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMNETAL
                    std::experimental::fixed_size_simd<U, N> a([this](int i) { return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a %= b;
                    _set(a, std::make_index_sequence<N>{});
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] %= scalar;
                    }
                #endif
                return *this;
            }

            // Bitwise operators

            template<typename U>
            constexpr vector<N, T> &operator&=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<T, N> a(this->data(), std::experimental::vector_aligned);
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a &= b;
                    a.copy_to(this->data(), std::experimental::vector_aligned);
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] &= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator|=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<T, N> a(this->data(), std::experimental::vector_aligned);
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a |= b;
                    a.copy_to(this->data(), std::experimental::vector_aligned);
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] |= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator^=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<T, N> a(this->data(), std::experimental::vector_aligned);
                    const std::experimental::fixed_size_simd<U, N> b(scalar);
                    a ^= b;
                    a.copy_to(this->data(), std::experimental::vector_aligned);
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] ^= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator<<=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<T, N> a(this->data(), std::experimental::vector_aligned);
                    a <<= scalar;
                    a.copy_to(this->data(), std::experimental::vector_aligned);
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] <<= scalar;
                    }
                #endif
                return *this;
            }

            template<typename U>
            constexpr vector<N, T> &operator>>=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<T, N> a(this->data(), std::experimental::vector_aligned);
                    a >>= scalar;
                    a.copy_to(this->data(), std::experimental::vector_aligned);
                #else
                    for (size_t i = 0; i < N; ++i) {
                        _data[i] >>= scalar;
                    }
                #endif
                return *this;
            }

            constexpr T dot(const vector<N, T> &other) const;

            double length() const {
                return std::sqrt(this->dot(*this));
            }

            double angle(const vector<N, T> &other) const {
                return std::acos(this->dot(other) / (this->length() * other.length()));
            }

            vector<N, T> unit() const {
                return *this / this->length();
            }

            T scalarProject(const vector<N, T> &other) const {
                return this->dot(other.unit());
            }

            constexpr T *data() {
                return this->_data;
            }

            constexpr const T *data() const {
                return this->_data;
            }

            T &operator[](size_t i) {
                if (i >= N)
                    throw std::out_of_range("Index out of range");
                return this->_data[i];
            }

            const T &operator[](size_t i) const {
                if (i >= N)
                    throw std::out_of_range("Index out of range");
                return this->_data[i];
            }
    };

    template<size_t N, typename T>
    requires std::is_arithmetic_v<T>
    vector<N, T> normalize(const vector<N, T> &v) {
        return v.unit();
    }

} // namespace showdown::math

#include "vector.inl"
