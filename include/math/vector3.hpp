
#pragma once

#ifdef SHOWDOWN_EXPERIMENTAL
    #include <experimental/simd>
#endif

#include <type_traits>

#include "math/vector.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    class vector<3, T> {
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
                        T z;
                    };
                    struct {
                        T r;
                        T g;
                        T b;
                    };
                    struct {
                        T s;
                        T t;
                        T p;
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
                union {
                    T z;
                    T b;
                    T p;
                };
            #endif

            constexpr size_t size() const {
                return 3;
            }

            constexpr vector() = default;

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename A>
                constexpr vector(std::experimental::simd<T, A> value) : x(value[0]), y(value[1]) {}
            #endif

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename U>
                constexpr void _set(const std::experimental::fixed_size_simd<U, 3> &simd) {
                    this->_data[0] = static_cast<T>(simd[0]);
                    this->_data[1] = static_cast<T>(simd[1]);
                    this->_data[2] = static_cast<T>(simd[2]);
                }
            #endif

            // Copy&move constructors

            constexpr vector(const vector<3, T> &other) = default;
            constexpr vector(vector<3, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr vector(const vector<3, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)) {}

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr vector(vector<3, U> &&other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)) {}

            // Scalar constructor

            explicit constexpr vector(T x) : x(x), y(x), z(x) {}
            explicit constexpr vector(T x, T y, T z) : x(x), y(y), z(z) {}

            template<typename U>
            explicit constexpr vector(const vector<1, U> &x, T y, T z) : x(static_cast<T>(x.x)), y(y), z(z) {}

            template<typename U>
            explicit constexpr vector(T x, const vector<1, U> &y, T z) : x(x), y(static_cast<T>(y.x)), z(z) {}

            template<typename U>
            explicit constexpr vector(T x, T y, const vector<1, U> &z) : x(x), y(y), z(static_cast<T>(z.x)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y, T z) : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)), z(z) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, T y, const vector<1, V> &z) : x(static_cast<T>(x.x)), y(y), z(static_cast<T>(z.x)) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, const vector<1, U> &y, const vector<1, V> &z) : x(x), y(static_cast<T>(y.x)), z(static_cast<T>(z.x)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y, const vector<1, W> &z) : x(static_cast<T>(x.x)), y(static_cast<T>(y.x)), z(static_cast<T>(z.x)) {}

            template<typename U>
            explicit constexpr vector(const vector<2, U> &xy, T z) : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(z) {}

            template<typename U>
            explicit constexpr vector(T x, const vector<2, U> &yz) : x(x), y(static_cast<T>(y.x)), z(static_cast<T>(yz.y)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, const vector<2, V> &yz) : x(static_cast<T>(x.x)), y(static_cast<T>(yz.x)), z(static_cast<T>(yz.y)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<2, U> &xy, const vector<1, V> &z) : x(static_cast<T>(xy.x)), y(static_cast<T>(xy.y)), z(static_cast<T>(z.x)) {}

            // Conversions from other vector types

            template<typename U>
            explicit constexpr vector(const vector<4, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)) {}

            template<size_t N, typename U>
            requires (N > 4)
            explicit constexpr vector(const vector<N, U> &other) : x(static_cast<T>(other[0])), y(static_cast<T>(other[1])), z(static_cast<T>(other[2])) {}

            // Assignments

            constexpr vector<3, T> &operator=(const vector<3, T> &other) = default;
            constexpr vector<3, T> &operator=(vector<3, T> &&other) = default;

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr vector<3, T> &operator=(const vector<3, U> &other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                this->z = static_cast<T>(other.z);
                return *this;
            }

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr vector<3, T> &operator=(vector<3, U> &&other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                this->z = static_cast<T>(other.z);
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<3, T> &operator+=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a += b;
                    _set(a);
                #else
                    this->x += scalar;
                    this->y += scalar;
                    this->z += scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<3, T> &operator-=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a -= b;
                    _set(a);
                #else
                    this->x -= scalar;
                    this->y -= scalar;
                    this->z -= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<3, T> &operator*=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a *= b;
                    _set(a);
                #else
                    this->x *= scalar;
                    this->y *= scalar;
                    this->z *= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<3, T> &operator/=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a /= b;
                    _set(a);
                #else
                    this->x /= scalar;
                    this->y /= scalar;
                    this->z /= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U> && std::is_integral_v<T>
            constexpr vector<3, T> &operator%=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a %= b;
                    _set(a);
                #else
                    this->x %= scalar;
                    this->y %= scalar;
                    this->z %= scalar;
                #endif
                return *this;
            }

            // Bitwise operators

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<3, T> &operator&=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a &= b;
                    _set(a);
                #else
                    this->x &= scalar;
                    this->y &= scalar;
                    this->z &= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<3, T> &operator|=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a |= b;
                    _set(a);
                #else
                    this->x |= scalar;
                    this->y |= scalar;
                    this->z |= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<3, T> &operator^=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a ^= b;
                    _set(a);
                #else
                    this->x ^= scalar;
                    this->y ^= scalar;
                    this->z ^= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<3, T> &operator<<=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a <<= b;
                    _set(a);
                #else
                    this->x <<= scalar;
                    this->y <<= scalar;
                    this->z <<= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<3, T> &operator>>=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 3> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 3> b(scalar);
                    a >>= b;
                    _set(a);
                #else
                    this->x >>= scalar;
                    this->y >>= scalar;
                    this->z >>= scalar;
                #endif
                return *this;
            }

            constexpr T dot(const vector<3, T> &other) const;
            constexpr vector<3, T> cross(const vector<3, T> &other) const;

            double length() const {
                return std::sqrt(this->dot(*this));
            }

            double angle(const vector<3, T> &other) const {
                return std::acos(this->dot(other) / (this->length() * other.length()));
            }

            vector<3, T> unit() const {
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

    // Vector operations

    template<typename T>
    constexpr vector<3, T> cross(const vector<3, T> &lhs, const vector<3, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::array<T, 3> aR = {lhs.y, lhs.z, lhs.x};
            std::array<T, 3> bR = {rhs.z, rhs.x, rhs.y};
            const std::experimental::fixed_size_simd<T, 3> a(aR.data());
            const std::experimental::fixed_size_simd<T, 3> b(bR.data());
            aR = {lhs.z, lhs.x, lhs.y};
            bR = {rhs.y, rhs.z, rhs.x};
            const std::experimental::fixed_size_simd<T, 3> c(aR.data());
            const std::experimental::fixed_size_simd<T, 3> d(bR.data());
            const auto e = a * b;
            const auto f = c * d;
            const auto g = e - f;
            return vector<3, T>(g[0], g[1], g[2]);
        #else
            return vector<3, T>(
                lhs.y * rhs.z - lhs.z * rhs.y,
                lhs.z * rhs.x - lhs.x * rhs.z,
                lhs.x * rhs.y - lhs.y * rhs.x
            );
        #endif
    }

} // namespace showdown::math

#include "vector3.inl"
