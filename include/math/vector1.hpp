
#pragma once

#include <type_traits>

#include "math/vector.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    class vector<1, T> {
        public:
            using type = T;

            union {
                T x;
                T r;
                T s;
            };

            constexpr size_t size() const {
                return 1;
            }

            constexpr vector() = default;

            // Copy&move constructors

            constexpr vector(const vector<1, T> &other) = default;
            constexpr vector(vector<1, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            constexpr vector(const vector<1, U> &other) : x(static_cast<T>(other.x)) {}

            template<typename U>
            constexpr vector(vector<1, U> &&other) : x(static_cast<T>(other.x)) {}

            // Scalar constructor

            explicit constexpr vector(T x) : x(x) {}

            // Conversions from other vector types

            template<typename U>
            explicit constexpr vector(const vector<2, U> &other) : x(static_cast<T>(other.x)) {}

            template<typename U>
            explicit constexpr vector(const vector<3, U> &other) : x(static_cast<T>(other.x)) {}

            template<typename U>
            explicit constexpr vector(const vector<4, U> &other) : x(static_cast<T>(other.x)) {}

            template<size_t N, typename U>
            requires (N > 4)
            explicit constexpr vector(const vector<N, U> &other) : x(static_cast<T>(other[0])) {}

            // Assignments

            constexpr vector<1, T> &operator=(const vector<1, T> &other) = default;
            constexpr vector<1, T> &operator=(vector<1, T> &&other) = default;

            template<typename U>
            constexpr vector<1, T> &operator=(const vector<1, U> &other) {
                this->x = static_cast<T>(other.x);
                return *this;
            }

            template<typename U>
            constexpr vector<1, T> &operator=(vector<1, U> &&other) {
                this->x = static_cast<T>(other.x);
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<1, T> &operator+=(U scalar) {
                this->x += static_cast<T>(scalar);
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<1, T> &operator-=(U scalar) {
                this->x -= static_cast<T>(scalar);
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<1, T> &operator*=(U scalar) {
                this->x *= static_cast<T>(scalar);
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr vector<1, T> &operator/=(U scalar) {
                this->x /= static_cast<T>(scalar);
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<T> && std::is_integral_v<U>
            constexpr vector<1, T> &operator%=(U scalar) {
                this->x %= static_cast<T>(scalar);
                return *this;
            }

            // Bitwise operators

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<1, T> &operator&=(U scalar) {
                this->x &= scalar;
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<1, T> &operator|=(U scalar) {
                this->x |= scalar;
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<1, T> &operator^=(U scalar) {
                this->x ^= scalar;
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<1, T> &operator<<=(U scalar) {
                this->x <<= scalar;
                return *this;
            }

            template<typename U>
            requires std::is_integral_v<U>
            constexpr vector<1, T> &operator>>=(U scalar) {
                this->x >>= scalar;
                return *this;
            }

            constexpr T dot(const vector<1, T> &other) const;

            double length() const {
                return this->x;
            }

            vector<1, T> unit() const {
                return vector<1, T>(static_cast<T>(1));
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

    // Unary arithmetic operators

    template<typename T>
    constexpr vector<1, T> operator+(const vector<1, T> &vec) {
        return vec;
    }

    template<typename T>
    constexpr vector<1, T> operator-(const vector<1, T> &vec) {
        return vector<1, T>(-vec.x);
    }

    // Binary arithmetic operators

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator+(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x + scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator+(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(vec.x + scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator-(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x - scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator-(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar - vec.x);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator*(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x * scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator*(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(vec.x * scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator/(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x / scalar);
    }

    template<typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr vector<1, T> operator/(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar / vec.x);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator%(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x % scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator%(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar % vec.x);
    }

    // Bitwise operators

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator&(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x & scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator&(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar & vec.x);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator|(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x | scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator|(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar | vec.x);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator^(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x ^ scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator^(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar ^vec.x);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator<<(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x << scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator<<(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar << vec.x);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator>>(const vector<1, T> &vec, U scalar) {
        return vector<1, T>(vec.x >> scalar);
    }

    template<typename T, typename U>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<1, T> operator>>(U scalar, const vector<1, T> &vec) {
        return vector<1, T>(scalar >> vec.x);
    }

    template<typename T>
    requires std::is_integral_v<T>
    constexpr vector<1, T> operator~(const vector<1, T> &vec) {
        return vector<1, T>(~vec.x);
    }

    // Equality operators

    template<typename T, typename U>
    constexpr bool operator==(const vector<1, T> &lhs, const vector<1, U> &rhs) {
        return lhs.x == rhs.x;
    }

    template<typename T, typename U>
    constexpr bool operator!=(const vector<1, T> &lhs, const vector<1, U> &rhs) {
        return lhs.x != rhs.x;
    }

    // Vector arithmetic operators

    template<typename T>
    constexpr vector<1, T> operator+(const vector<1, T> &lhs, const vector<1, T> &rhs) {
        return vector<1, T>(lhs.x + rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator-(const vector<1, T> &lhs, const vector<1, T> &rhs) {
        return vector<1, T>(lhs.x - rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator*(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x * rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator/(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x / rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator%(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x % rhs.x);
    }

    // Bitwise operators

    template<typename T>
    constexpr vector<1, T> operator&(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x & rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator|(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x | rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator^(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x ^ rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator<<(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x << rhs.x);
    }

    template<typename T>
    constexpr vector<1, T> operator>>(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return vector<1, T>(lhs.x >> rhs.x);
    }

    // Vector operations

    template<typename T>
    constexpr T dot(const vector<1, T> &lhs, const vector<1, T> &rhs)  {
        return lhs.x * rhs.x;
    }

} // namespace showdown::math

#include "vector1.inl"
