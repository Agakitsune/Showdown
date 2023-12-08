
#pragma once

#ifdef SHOWDOWN_EXPERIMENTAL
    #include <experimental/simd>
#endif

#include <type_traits>

#include "math/vector.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    class vector<4, T> {
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
                        T w;
                    };
                    struct {
                        T r;
                        T g;
                        T b;
                        T a;
                    };
                    struct {
                        T s;
                        T t;
                        T p;
                        T q;
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
                union {
                    T w;
                    T a;
                    T q;
                };
            #endif

            constexpr size_t size() const {
                return 4;
            }

            constexpr vector() = default;

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename A>
                constexpr vector(std::experimental::simd<T, A> value) : x(value[0]), y(value[1]) {}
            #endif

            #ifdef SHOWDOWN_EXPERIMENTAL
                template<typename U>
                constexpr void _set(const std::experimental::fixed_size_simd<U, 4> &simd) {
                    this->_data[0] = static_cast<T>(simd[0]);
                    this->_data[1] = static_cast<T>(simd[1]);
                    this->_data[2] = static_cast<T>(simd[2]);
                    this->_data[3] = static_cast<T>(simd[3]);
                }
            #endif

            // Copy&move constructors

            constexpr vector(const vector<4, T> &other) = default;
            constexpr vector(vector<4, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            constexpr vector(const vector<4, U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)), w(static_cast<T>(other.w)) {}

            template<typename U>
            constexpr vector(vector<4, U> &&other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)), w(static_cast<T>(other.w)) {}

            // Scalar constructor

            explicit constexpr vector(T x) : x(x), y(x), z(x), w(x) {}
            explicit constexpr vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

            template<typename U>
            explicit constexpr vector(const vector<1, U> &x, T y, T z, T w) : x(static_cast<T>(x.x)), y(y), z(z), w(w) {}

            template<typename U>
            explicit constexpr vector(T x, const vector<1, U> &y, T z, T w) : x(x), y(static_cast<T>(y.y)), z(z), w(w) {}

            template<typename U>
            explicit constexpr vector(T x, T y, const vector<1, U> &z, T w) : x(x), y(y), z(static_cast<T>(z.z)), w(w) {}

            template<typename U>
            explicit constexpr vector(T x, T y, T z, const vector<1, U> &w) : x(x), y(y), z(z), w(static_cast<T>(w.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, U> &y, T z, T w) : x(static_cast<T>(x.x)), y(static_cast<T>(x.y)), z(z), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, T y, const vector<1, U> &z, T w) : x(static_cast<T>(x.x)), y(y), z(static_cast<T>(z.z)), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, U> &x, T y, T z, const vector<1, V> &w) : x(static_cast<T>(x.x)), y(y), z(z), w(static_cast<T>(w.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, const vector<1, U> &y, const vector<1, V> &z, T w) : x(x), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, const vector<1, U> &y, T z, const vector<1, V> &w) : x(x), y(static_cast<T>(y.y)), z(z), w(static_cast<T>(w.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, T y, const vector<1, U> &z, const vector<1, V> &w) : x(x), y(y), z(static_cast<T>(z.z)), w(static_cast<T>(w.w)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y, const vector<1, W> &z, T w) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(w) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y, T z, const vector<1, W> &w) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(z), w(static_cast<T>(w.w)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, U> &x, T y, const vector<1, V> &z, const vector<1, W> &w) : x(static_cast<T>(x.x)), y(y), z(static_cast<T>(z.z)), w(static_cast<T>(w.w)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(T x, const vector<1, U> &y, const vector<1, V> &z, const vector<1, W> &w) : x(x), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(static_cast<T>(w.w)) {}

            template<typename U, typename V, typename W, typename X>
            explicit constexpr vector(const vector<1, U> &x, const vector<1, V> &y, const vector<1, W> &z, const vector<1, X> &w) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(static_cast<T>(w.w)) {}


            template<typename U>
            explicit constexpr vector(const vector<2, U> &xy, T z, T w) : x(static_cast<T>(x.x)), y(static_cast<T>(x.y)), z(z), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<2, U> &xy, const vector<1, V> &z, T w) : x(static_cast<T>(x.x)), y(static_cast<T>(x.y)), z(static_cast<T>(z.z)), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<2, U> &xy, T z, const vector<1, V> &w) : x(static_cast<T>(x.x)), y(static_cast<T>(x.y)), z(z), w(static_cast<T>(w.w)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<2, U> &xy, const vector<1, V> &z, const vector<1, W> &w) : x(static_cast<T>(x.x)), y(static_cast<T>(x.y)), z(static_cast<T>(z.z)), w(static_cast<T>(w.w)) {}


            template<typename U>
            explicit constexpr vector(T x, const vector<2, U> &yz, T w) : x(x), y(static_cast<T>(y.y)), z(static_cast<T>(y.z)), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, const vector<2, U> &yz, const vector<1, V> &w) : x(x), y(static_cast<T>(y.y)), z(static_cast<T>(y.z)), w(static_cast<T>(w.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, V> &x, const vector<2, U> &yz, T w) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(static_cast<T>(y.z)), w(w) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, V> &x, const vector<2, U> &yz, const vector<1, W> &w) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(static_cast<T>(y.z)), w(static_cast<T>(w.w)) {}


            template<typename U>
            explicit constexpr vector(T x, T y, const vector<2, U> &zw) : x(x), y(y), z(static_cast<T>(z.z)), w(static_cast<T>(z.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, V> &x, T y, const vector<2, U> &zw) : x(static_cast<T>(x.x)), y(y), z(static_cast<T>(z.z)), w(static_cast<T>(z.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(T x, const vector<1, V> &y, const vector<2, U> &zw) : x(x), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(static_cast<T>(z.w)) {}

            template<typename U, typename V, typename W>
            explicit constexpr vector(const vector<1, V> &x, const vector<1, V> &y, const vector<2, U> &zw) : x(static_cast<T>(x.x)), y(static_cast<T>(y.y)), z(static_cast<T>(z.z)), w(static_cast<T>(z.w)) {}


            template<typename U>
            explicit constexpr vector(const vector<3, U> &xyz, T w) : x(static_cast<T>(xyz.x)), y(static_cast<T>(xyz.y)), z(static_cast<T>(xyz.z)), w(w) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<3, U> &xyz, const vector<1, V> &w) : x(static_cast<T>(xyz.x)), y(static_cast<T>(xyz.y)), z(static_cast<T>(xyz.z)), w(static_cast<T>(w.w)) {}

            template<typename U>
            explicit constexpr vector(T x, const vector<3, U> &yzw) : x(x), y(static_cast<T>(yzw.y)), z(static_cast<T>(yzw.z)), w(static_cast<T>(yzw.w)) {}

            template<typename U, typename V>
            explicit constexpr vector(const vector<1, V> &x, const vector<3, U> &yzw) : x(static_cast<T>(x.x)), y(static_cast<T>(yzw.y)), z(static_cast<T>(yzw.z)), w(static_cast<T>(yzw.w)) {}

            // Conversions from other vector types

            template<size_t N, typename U>
            requires (N > 4)
            explicit constexpr vector(const vector<N, U> &other) : x(static_cast<T>(other[0])), y(static_cast<T>(other[1])), z(static_cast<T>(other[2])), w(static_cast<T>(other[3])) {}

            // Assignments

            constexpr vector<4, T> &operator=(const vector<4, T> &other) = default;
            constexpr vector<4, T> &operator=(vector<4, T> &&other) = default;

            template<typename U>
            constexpr vector<4, T> &operator=(const vector<4, U> &other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                this->z = static_cast<T>(other.z);
                this->w = static_cast<T>(other.w);
                return *this;
            }

            template<typename U>
            constexpr vector<4, T> &operator=(vector<4, U> &&other) {
                this->x = static_cast<T>(other.x);
                this->y = static_cast<T>(other.y);
                this->z = static_cast<T>(other.z);
                this->w = static_cast<T>(other.w);
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<4, T> &operator+=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a += b;
                    _set(a);
                #else
                    this->x += scalar;
                    this->y += scalar;
                    this->z += scalar;
                    this->w += scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<4, T> &operator-=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a -= b;
                    _set(a);
                #else
                    this->x -= scalar;
                    this->y -= scalar;
                    this->z -= scalar;
                    this->w -= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<4, T> &operator*=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a *= b;
                    _set(a);
                #else
                    this->x *= scalar;
                    this->y *= scalar;
                    this->z *= scalar;
                    this->w *= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<4, T> &operator/=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a /= b;
                    _set(a);
                #else
                    this->x /= scalar;
                    this->y /= scalar;
                    this->z /= scalar;
                    this->w /= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator%=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a %= b;
                    _set(a);
                #else
                    this->x %= scalar;
                    this->y %= scalar;
                    this->z %= scalar;
                    this->w %= scalar;
                #endif
                return *this;
            }

            // Bitwise operators

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator&=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a &= b;
                    _set(a);
                #else
                    this->x &= scalar;
                    this->y &= scalar;
                    this->z &= scalar;
                    this->w &= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator|=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a |= b;
                    _set(a);
                #else
                    this->x |= scalar;
                    this->y |= scalar;
                    this->z |= scalar;
                    this->w |= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator^=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a ^= b;
                    _set(a);
                #else
                    this->x ^= scalar;
                    this->y ^= scalar;
                    this->z ^= scalar;
                    this->w ^= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator<<=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a <<= b;
                    _set(a);
                #else
                    this->x <<= scalar;
                    this->y <<= scalar;
                    this->z <<= scalar;
                    this->w <<= scalar;
                #endif
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<4, T> &operator>>=(U scalar) {
                #ifdef SHOWDOWN_EXPERIMENTAL
                    std::experimental::fixed_size_simd<U, 4> a([this](int i){ return static_cast<U>(this->data()[i]); });
                    const std::experimental::fixed_size_simd<U, 4> b(scalar);
                    a >>= b;
                    _set(a);
                #else
                    this->x >>= scalar;
                    this->y >>= scalar;
                    this->z >>= scalar;
                    this->w >>= scalar;
                #endif
                return *this;
            }

            constexpr T dot(const vector<4, T> &other) const;

            double length() const {
                return std::sqrt(this->dot(*this));
            }

            double angle(const vector<4, T> &other) const {
                return std::acos(this->dot(other) / (this->length() * other.length()));
            }

            vector<4, T> unit() const {
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

#include "vector4.inl"
