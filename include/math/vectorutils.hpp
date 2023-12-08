
#pragma once

#include <iostream>

#ifdef SHOWDOWN_EXPERIMENTAL
    #include <experimental/simd>
#endif

#include <type_traits>

#include "vector.hpp"

namespace showdown::math {

    template<typename T, size_t N>
    constexpr vector<N, T> operator+(const vector<N, T> &vec) {
        return vec;
    }

    template<typename T, size_t N>
    constexpr vector<N, T> operator-(const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(vec.data(), std::experimental::vector_aligned);
            return vector<N, T>(-a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = -vec[i];
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator+(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a += b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] + scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator+(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a += b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] + scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator-(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a -= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] - scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator-(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a += -a;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar - vec[i];
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator*(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a *= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] * scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator*(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a *= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] * scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator/(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a /= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] / scalar;
            }
            return result;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_arithmetic_v<U>
    constexpr vector<N, T> operator/(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            std::experimental::fixed_size_simd<U, N> b(scalar);
            b /= a;
            return vector<N, T>(b);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar / vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator%(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a %= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] % scalar;
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator%(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            std::experimental::fixed_size_simd<U, N> b(scalar);
            b %= a;
            return vector<N, T>(b);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar % vec[i];
            }
            return vec;
        #endif
    }

    // Bitwise operators

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator&(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a &= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar & vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator&(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            std::experimental::fixed_size_simd<U, N> b(scalar);
            b &= a;
            return vector<N, T>(b);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar & vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator|(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a |= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar | vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator|(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            std::experimental::fixed_size_simd<U, N> b(scalar);
            b |= a;
            return vector<N, T>(b);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar | vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator^(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a ^= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar ^ vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator^(U scalar, const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            std::experimental::fixed_size_simd<U, N> b(scalar);
            b ^= a;
            return vector<N, T>(b);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = scalar ^ vec[i];
            }
            return vec;
        #endif
    }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator<<(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a <<= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] << scalar;
            }
            return vec;
        #endif
    }

    // template<typename T, typename U, size_t N>
    // requires std::is_integral_v<T> && std::is_integral_v<U>
    // constexpr vector<N, T> operator<<(U scalar, const vector<N, T> &vec) {
    //     #ifdef SHOWDOWN_EXPERIMENTAL
    //         const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
    //         std::experimental::fixed_size_simd<U, N> b(scalar);
    //         b <<= a;
    //         return vector<N, T>(b);
    //     #else
    //         vector<N, T> result;
    //         for (size_t i = 0; i < N; ++i) {
    //             result[i] = scalar << vec[i];
    //         }
    //         return vec;
    //     #endif
    // }

    template<typename T, typename U, size_t N>
    requires std::is_integral_v<T> && std::is_integral_v<U>
    constexpr vector<N, T> operator>>(const vector<N, T> &vec, U scalar) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
            const std::experimental::fixed_size_simd<U, N> b(scalar);
            a >>= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = vec[i] >> scalar;
            }
            return vec;
        #endif
    }

    // template<typename T, typename U, size_t N>
    // requires std::is_integral_v<T> && std::is_integral_v<U>
    // constexpr vector<N, T> operator>>(U scalar, const vector<N, T> &vec) {
    //     #ifdef SHOWDOWN_EXPERIMENTAL
    //         const std::experimental::fixed_size_simd<U, N> a([vec](int i) { return static_cast<U>(vec.data()[i]); });
    //         std::experimental::fixed_size_simd<U, N> b(scalar);
    //         b >>= a;
    //         return vector<N, T>(b);
    //     #else
    //         vector<N, T> result;
    //         for (size_t i = 0; i < N; ++i) {
    //             result[i] = scalar >> vec[i];
    //         }
    //         return vec;
    //     #endif
    // }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator~(const vector<N, T> &vec) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(vec.data(), std::experimental::vector_aligned);
            return vector<N, T>(~a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = ~vec[i];
            }
            return result;
        #endif
    }

    // Equality operators

    template<typename T, size_t N>
    constexpr bool operator==(const vector<N, T> &lhs, const vector<N, T> &rhs) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            return std::experimental::all_of(a == b);
        #else
            for (size_t i = 0; i < N; ++i) {
                if (lhs[i] != rhs[i]) {
                    return false;
                }
            }
            return true;
        #endif
    }

    template<typename T, size_t N>
    constexpr bool operator!=(const vector<N, T> &lhs, const vector<N, T> &rhs) {
        return !(lhs == rhs);
    }

    // Vector arithmetic operators

    template<typename T, size_t N>
    constexpr vector<N, T> operator+(const vector<N, T> &lhs, const vector<N, T> &rhs) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a += b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] + rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    constexpr vector<N, T> operator-(const vector<N, T> &lhs, const vector<N, T> &rhs) {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a -= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] - rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    constexpr vector<N, T> operator*(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a *= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] * rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    constexpr vector<N, T> operator/(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a /= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] / rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator%(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a %= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] % rhs[i];
            }
            return result;
        #endif
    }

    // Bitwise operators

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator&(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a &= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] & rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator|(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a |= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] | rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator^(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a ^= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] ^ rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator<<(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a <<= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] << rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_integral_v<T>
    constexpr vector<N, T> operator>>(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a >>= b;
            return vector<N, T>(a);
        #else
            vector<N, T> result;
            for (size_t i = 0; i < N; ++i) {
                result[i] = lhs[i] >> rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    requires std::is_arithmetic_v<T>
    constexpr T dot(const vector<N, T> &lhs, const vector<N, T> &rhs)  {
        #ifdef SHOWDOWN_EXPERIMENTAL
            std::experimental::fixed_size_simd<T, N> a(lhs.data(), std::experimental::vector_aligned);
            const std::experimental::fixed_size_simd<T, N> b(rhs.data(), std::experimental::vector_aligned);
            a *= b;
            return std::experimental::reduce(a);
        #else
            T result = 0;
            for (size_t i = 0; i < N; ++i) {
                result += lhs[i] * rhs[i];
            }
            return result;
        #endif
    }

    template<typename T, size_t N>
    std::ostream &operator<<(std::ostream &s, const vector<N, T> &vec) {
        const T *data = vec.data();
        s << '[';
        for (size_t i = 0; i < N; ++i) {
            s << data[i];
            if (i < N - 1) {
                s << ", ";
            }
        }
        return s << ']';
    }

} // namespace showdown::math
