
#pragma once

#ifdef SHOWDOWN_EXPERIMENTAL
    #include <experimental/simd>
#endif

#include <type_traits>

#include "math/vector.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    class vector<2, T> {
        public:
            using type = T;

            #ifdef SHOWDOWN_USE_ANONYMOUS
                // Use to ignore error since anonymous struct is forbidden by C++ ISO standard
                #pragma GCC diagnostic push
                #pragma GCC diagnostic ignored "-Wpedantic"

                union {
                    struct {
                        T x;
                        T y;
                    };
                    struct {
                        T r;
                        T g;
                    };
                    struct {
                        T s;
                        T t;
                    };
                };
            #else
                union {
                    T x;
                    T r;
                    T s;
                };
                union {
                    T y;
                    T g;
                    T t;
                };
            #endif

            constexpr size_t size() const {
                return 2;
            }

            constexpr vector() = default;

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename A>
                constexpr vector(std::experimental::simd<T, A> value) : x(value[0]), y(value[1]) {}
            #endif

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename U>
                constexpr void _set(const std::experimental::fixed_size_simd<U, 2> &simd) {
                    this->_data[0] = static_cast<T>(simd[0]);
                    this->_data[1] = static_cast<T>(simd[1]);
                }
            #endif

            // Copy&move constructors

            constexpr vector(const vector<2, T> &other) = default;
            constexpr vector(vector<2, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            constexpr vector(const vector<2, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

            template<typename U>
            constexpr vector(vector<2, U> &&other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

            // Scalar constructor

            explicit constexpr vector(T x) : x(x), y(x) {}
            explicit constexpr vector(T x, T y) : x(x), y(y) {}

            template<typename U>
            explicit constexpr vector(const vector<1, U> &x, T y) : x(static_cast<T>(x.x)), y(y) {}

            template<typename U>
            explicit constexpr vector(T x, const vector<1, U> &y) : x(x), y(static_cast<T>(y.x)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y) : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)) {}

            // Conversions from other vector types

            template<typename U>
            explicit constexpr vector(const vector<3, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

            template<typename U>
            explicit constexpr vector(const vector<4, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

            template<size_t N, typename U>
            requires (N > 4)
            explicit constexpr vector(const vector<N, U> &other) : x(static_cast<T>(other[0])), y(static_cast<T>(other[1])) {}

            // Assignments

            constexpr vector<2, T> &operator=(const vector<2, T> &other) = default;
            constexpr vector<2, T> &operator=(vector<2, T> &&other) = default;

            template<typename U>
            constexpr vector<2, T> &operator=(const vector<2, U> &other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                return *this;
            }

            template<typename U>
            constexpr vector<2, T> &operator=(vector<2, U> &&other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<2, T> &operator+=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a += b;
                    _set(a);
                #else
                    this->x += scalar;
                    this->y += scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<2, T> &operator-=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a -= b;
                    _set(a);
                #else
                    this->x -= scalar;
                    this->y -= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<2, T> &operator*=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a *= b;
                    _set(a);
                #else
                    this->x *= scalar;
                    this->y *= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<2, T> &operator/=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a /= b;
                    _set(a);
                #else
                    this->x /= scalar;
                    this->y /= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator%=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a %= b;
                    _set(a);
                #else
                    this->x %= scalar;
                    this->y %= scalar;
                #endif
                return *this;
            }

            // Bitwise operators

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator&=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a &= b;
                    _set(a);
                #else
                    this->x &= scalar;
                    this->y &= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator|=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a |= b;
                    _set(a);
                #else
                    this->x |= scalar;
                    this->y |= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator^=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a ^= b;
                    _set(a);
                #else
                    this->x ^= scalar;
                    this->y ^= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator<<=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a <<= b;
                    _set(a);
                #else
                    this->x <<= scalar;
                    this->y <<= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<2, T> &operator>>=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 2> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 2> b(scalar);
                    a >>= b;
                    _set(a);
                #else
                    this->x >>= scalar;
                    this->y >>= scalar;
                #endif
                return *this;
            }

            constexpr T dot(const vector<2, T> &other) const;

            double length() const {
                return std::sqrt(this->dot(*this));
            }

            double angle(const vector<2, T> &other) const {
                return std::acos(this->dot(other) / (this->length() * other.length()));
            }

            vector<2, T> unit() const {
                return *this / this->length();
            }

            T scalarProject(const vector<2, T> &other) const {
                return this->dot(other.unit());
            }

            constexpr T *data() {
                return &this->x;
            }

            constexpr const T *data() const {
                return &this->x;
            }

            T &operator[](size_t i) {
                if (i >= this->size())
                    throw std::out_of_range("Index out of range");
                return this->data()[i];
            }

            const T &operator[](size_t i) const {
                if (i >= this->size())
                    throw std::out_of_range("Index out of range");
                return this->data()[i];
            }
    };

} // namespace showdown::math

#include "vector2.inl"
