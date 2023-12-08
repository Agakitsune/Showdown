
#pragma once

#include <type_traits>
#include <cstddef>
#include <ostream>

#include "vector.hpp"

namespace showdown::math {

    template<size_t M, size_t N, typename T>
    requires std::is_arithmetic_v<T>
    class matrix {
        T _data[M][N] = {0};

        public:
            using type = T;

            constexpr size_t rows() const {
                return M;
            }

            constexpr size_t columns() const {
                return N;
            }

            // Unit matrix constructor
            constexpr matrix() {
                constexpr size_t min = M < N ? M : N;
                for (size_t i = 0; i < min; ++i) {
                    _data[i][i] = 1;
                }
            }
            
            // Copy&Move constructors

            constexpr matrix(const matrix<M, N, T> &other) = default;
            constexpr matrix(matrix<M, N, T> &&other) = default;

            // Conversion copy&move constructors

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr matrix(const matrix<M, N, U> &other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        _data[i][j] = static_cast<T>(other._data[i][j]);
                    }
                }
            }

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr matrix(matrix<M, N, U> &&other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        _data[i][j] = static_cast<T>(other._data[i][j]);
                    }
                }
            }

            template<typename U>
            requires std::is_convertible_v<U, T>
            constexpr matrix(const U (&arr)[M][N]) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        _data[i][j] = static_cast<T>(arr[i][j]);
                    }
                }
            }

            // Scalar constructor

            explicit constexpr matrix(T x) {
                for (size_t i = 0; i < M; ++i) {
                    _data[i][i] = x;
                }
            }

            template<typename... Ts>
            requires std::conjunction_v<std::is_convertible<Ts, T>...> && (sizeof...(Ts) == (M * N))
            explicit constexpr matrix(Ts... v) {
                T arr[] = {static_cast<T>(v)...};
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        _data[i][j] = arr[i * M + j];
                    }
                }
            }

            // Conversions from other matrix types

            template<size_t O, size_t P, typename U>
            requires std::is_convertible_v<U, T>
            explicit constexpr matrix(const matrix<O, P, U> &other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        if (i < O && j < P) {
                            _data[i][j] = other[i][j];
                        } else {
                            if constexpr (M == N) {
                                _data[i][j] = static_cast<T>(i == j);
                            } else {
                                _data[i][j] = static_cast<T>(0);
                            }
                        }
                    }
                }
            }

            // Assignments

            constexpr matrix<M, N, T> &operator=(const matrix<M, N, T> &other) = default;
            constexpr matrix<M, N, T> &operator=(matrix<M, N, T> &&other) = default;

            template<size_t O, size_t P, typename U>
            requires std::is_convertible_v<U, T> && (O > M) && (P > N)
            constexpr matrix<M, N, T> &operator=(const matrix<O, P, U> &other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] = other._data[i][j];
                    }
                }
                return *this;
            }

            template<size_t O, size_t P, typename U>
            requires std::is_convertible_v<U, T> && (O > M) && (P > N)
            constexpr matrix<M, N, T> &operator=(matrix<O, P, U> &&other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] = other._data[i][j];
                    }
                }
                return *this;
            }

            // Unary Scalar Arithmetic operators

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr matrix<M, N, T> &operator+=(U x) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] += x;
                    }
                }
                return *this;
            }

            template<typename U>
            constexpr matrix<M, N, T> &operator+=(const matrix<M, N, U> &other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] += other[i][j];
                    }
                }
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr matrix<M, N, T> &operator-=(U x) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] -= x;
                    }
                }
                return *this;
            }

            template<typename U>
            constexpr matrix<M, N, T> &operator-=(const matrix<M, N, U> &other) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] -= other[i][j];
                    }
                }
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr matrix<M, N, T> &operator*=(U x) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] *= x;
                    }
                }
                return *this;
            }

            template<typename U>
            requires (M == N)
            constexpr matrix<M, N, T> &operator*=(const matrix<M, N, U> &other) {
                matrix<M, N, T> temp = *this;
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; j++) {
                        this->_data[i][j] = 0;
                        for (size_t k = 0; k < M; ++k) {
                            this->_data[i][j] += temp[i][k] * other[k][j];
                        }
                    }
                }
                return *this;
            }

            template<typename U>
            requires std::is_arithmetic_v<U>
            constexpr matrix<M, N, T> &operator/=(U x) {
                for (size_t i = 0; i < M; ++i) {
                    for (size_t j = 0; j < N; ++j) {
                        this->_data[i][j] /= x;
                    }
                }
                return *this;
            }

            // Methods

            T *operator[](size_t i) {
                return _data[i];
            }

            const T *operator[](size_t i) const {
                return _data[i];
            }
    };

    // Unary Arithmetic operators

    template<size_t M, size_t N, typename T>
    constexpr matrix<M, N, T> operator+(const matrix<M, N, T> &mat) {
        return mat;
    }

    template<size_t M, size_t N, typename T>
    constexpr matrix<M, N, T> operator-(const matrix<M, N, T> &mat) {
        return mat * -1;
    }

    // Binary Scalar Arithmetic operators

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator+(const matrix<M, N, T> &mat, U x) {
        matrix<M, N, T> temp = mat;
        temp += x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator+(U x, const matrix<M, N, T> &mat) {
        matrix<M, N, T> temp = mat;
        temp += x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator-(const matrix<M, N, T> &mat, U x) {
        matrix<M, N, T> temp = mat;
        temp -= x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator-(U x, const matrix<M, N, T> &mat) {
        matrix<M, N, T> temp = -mat;
        temp += x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator*(const matrix<M, N, T> &mat, U x) {
        matrix<M, N, T> temp = mat;
        temp *= x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator*(U x, const matrix<M, N, T> &mat) {
        matrix<M, N, T> temp = mat;
        temp *= x;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_arithmetic_v<U>
    constexpr matrix<M, N, T> operator/(const matrix<M, N, T> &mat, U x) {
        matrix<M, N, T> temp = mat;
        temp /= x;
        return temp;
    }

    // Binary Matrix Arithmetic operators

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_convertible_v<U, T>
    constexpr matrix<M, N, T> operator+(const matrix<M, N, T> &lhs, const matrix<M, N, U> &rhs) {
        matrix<M, N, T> temp = lhs;
        temp += rhs;
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    requires std::is_convertible_v<U, T>
    constexpr matrix<M, N, T> operator-(const matrix<M, N, T> &lhs, const matrix<M, N, U> &rhs) {
        matrix<M, N, T> temp = lhs;
        temp -= rhs;
        return temp;
    }

    template<size_t M, size_t N, size_t P, typename T, typename U>
    constexpr matrix<M, P, T> operator*(const matrix<M, N, T> &lhs, const matrix<N, P, U> &rhs) {
        // std::cout << lhs << std::endl;
        // std::cout << rhs << std::endl;
        matrix<M, P, T> temp;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < P; ++j) {
                // std::cout << "Calculating for " << i << "x" << j << std::endl;
                temp[i][j] = 0;
                for (size_t k = 0; k < N; ++k) {
                    // std::cout << "Adding " << lhs[i][k] << " * " << rhs[k][j] << std::endl;
                    temp[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }
        return temp;
    }

    // Binary Vector Arithmetic operators

    template<size_t M, size_t N, typename T, typename U>
    constexpr vector<M, T> operator*(const matrix<M, N, T> &mat, const vector<N, U> &vec) {
        vector<M, T> temp;
        for (size_t i = 0; i < M; ++i) {
            temp[i] = 0;
            for (size_t j = 0; j < N; ++j) {
                temp[i] += mat[i][j] * vec[j];
            }
        }
        return temp;
    }

    template<size_t M, size_t N, typename T, typename U>
    constexpr vector<N, T> operator*(const vector<M, U> &vec, const matrix<M, N, T> &mat) {
        vector<N, T> temp;
        for (size_t i = 0; i < N; ++i) {
            temp[i] = 0;
            for (size_t j = 0; j < M; ++j) {
                temp[i] += vec[j] * mat[j][i];
            }
        }
        return temp;
    }

    // Binary Skew Vector Arithmetic operators

    template<size_t M, size_t N, size_t O, typename T, typename U>
    requires std::is_convertible_v<U, T> && (N > O)
    constexpr vector<O, T> operator*(const matrix<M, N, T> &mat, const vector<O, U> &vec) {
        vector<O, T> temp;
        for (size_t i = 0; i < O; ++i) {
            temp[i] = 0;
            for (size_t j = 0; j < O; ++j) {
                temp[i] += mat[i][j] * vec[j];
            }
        }
        return temp;
    }

    template<size_t M, size_t N, size_t O, typename T, typename U>
    requires (M > O)
    constexpr vector<O, T> operator*(const vector<O, U> &vec, const matrix<M, N, T> &mat) {
        vector<O, T> temp;
        for (size_t i = 0; i < O; ++i) {
            temp[i] = 0;
            for (size_t j = 0; j < O; ++j) {
                temp[i] += vec[j] * mat[i][j];
            }
        }
        return temp;
    }

    // Misc operations

    template<size_t M, size_t N, typename T>
    constexpr matrix<N, M, T> transpose(const matrix<M, N, T> &mat) {
        matrix<N, M, T> temp;
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; j++) {
                temp[j][i] = mat[i][j];
            }
        }
        return temp;
    }

    // Transformation

    template<typename T>
    matrix<4, 4, T> translate(const matrix<4, 4, T> &mat, const vector<3, T> &vec) {
        matrix<4, 4, T> temp = mat;
        temp[0][3] = temp[0][3] + vec.x;
        temp[1][3] = temp[1][3] + vec.y;
        temp[2][3] = temp[2][3] + vec.z;
        return temp;
    }

    template<typename T>
    matrix<4, 4, T> rotationX(const matrix<4, 4, T> &mat, T angle) {
        const T c = std::cos(angle * M_PI / 180);
        const T s = std::sin(angle * M_PI / 180);

        matrix<4, 4, T> temp = mat;

        temp[0][1] = c * mat[0][1] + s * mat[0][2];
        temp[0][2] = -s * mat[0][1] + c * mat[0][2];

        temp[1][1] = c * mat[1][1] + s * mat[1][2];
        temp[1][2] = -s * mat[1][1] + c * mat[1][2];

        temp[2][1] = c * mat[2][1] + s * mat[2][2];
        temp[2][2] = -s * mat[2][1] + c * mat[2][2];

        temp[3][1] = c * mat[3][1] + s * mat[3][2];
        temp[3][2] = -s * mat[3][1] + c * mat[3][2];

        return temp;
    }

    template<typename T>
    matrix<4, 4, T> rotationY(const matrix<4, 4, T> &mat, T angle) {
        const T c = std::cos(angle * M_PI / 180);
        const T s = std::sin(angle * M_PI / 180);

        matrix<4, 4, T> temp = mat;

        temp[0][0] = c * mat[0][0] - s * mat[0][2];
        temp[0][2] = s * mat[0][0] + c * mat[0][2];

        temp[1][0] = c * mat[1][0] - s * mat[1][2];
        temp[1][2] = s * mat[1][0] + c * mat[1][2];

        temp[2][0] = c * mat[2][0] - s * mat[2][2];
        temp[2][2] = s * mat[2][0] + c * mat[2][2];

        temp[3][0] = c * mat[3][0] - s * mat[3][2];
        temp[3][2] = s * mat[3][0] + c * mat[3][2];

        return temp;
    }

    template<typename T>
    matrix<4, 4, T> rotationZ(const matrix<4, 4, T> &mat, T angle) {
        const T c = std::cos(angle * M_PI / 180);
        const T s = std::sin(angle * M_PI / 180);

        matrix<4, 4, T> temp = mat;

        temp[0][0] = c * mat[0][0] + -s * mat[0][1];
        temp[0][1] = s * mat[0][0] + c * mat[0][1];

        temp[1][0] = c * mat[1][0] + -s * mat[1][1];
        temp[1][1] = s * mat[1][0] + c * mat[1][1];

        temp[2][0] = c * mat[2][0] + -s * mat[2][1];
        temp[2][1] = s * mat[2][0] + c * mat[2][1];

        temp[3][0] = c * mat[3][0] + -s * mat[3][1];
        temp[3][1] = s * mat[3][0] + c * mat[3][1];

        return temp;
    }

    template<typename T>
    matrix<4, 4, T> rotation(const matrix<4, 4, T> &mat, const vector<3, T> &angles) {
        const T cX = std::cos(angles.x * M_PI / 180.0);
        const T cY = std::cos(angles.y * M_PI / 180.0);
        const T cZ = std::cos(angles.z * M_PI / 180.0);
        const T sX = std::sin(angles.x * M_PI / 180.0);
        const T sY = std::sin(angles.y * M_PI / 180.0);
        const T sZ = std::sin(angles.z * M_PI / 180.0);

        matrix<4, 4, T> temp = mat;

        temp[0][0] = cY * cZ * mat[0][0] + (sX * sY * cZ - cX * sZ) * mat[1][0] + (cX * sY * cZ + sX * sZ) * mat[2][0];
        temp[1][0] = cY * sZ * mat[0][0] + (sX * sY * sZ + cX * cZ) * mat[1][0] + (cX * sY * sZ - sX * cZ) * mat[2][0];
        temp[2][0] = -sY * mat[0][0] + sX * cY * mat[1][0] + cX * cY * mat[2][0];

        temp[0][1] = cY * cZ * mat[0][1] + (sX * sY * cZ - cX * sZ) * mat[1][1] + (cX * sY * cZ + sX * sZ) * mat[2][1];
        temp[1][1] = cY * sZ * mat[0][1] + (sX * sY * sZ + cX * cZ) * mat[1][1] + (cX * sY * sZ - sX * cZ) * mat[2][1];
        temp[2][1] = -sY * mat[0][1] + sX * cY * mat[1][1] + cX * cY * mat[2][1];

        temp[0][2] = cY * cZ * mat[0][2] + (sX * sY * cZ - cX * sZ) * mat[1][2] + (cX * sY * cZ + sX * sZ) * mat[2][2];
        temp[1][2] = cY * sZ * mat[0][2] + (sX * sY * sZ + cX * cZ) * mat[1][2] + (cX * sY * sZ - sX * cZ) * mat[2][2];
        temp[2][2] = -sY * mat[0][2] + sX * cY * mat[1][2] + cX * cY * mat[2][2];

        temp[0][3] = cY * cZ * mat[0][3] + (sX * sY * cZ - cX * sZ) * mat[1][3] + (cX * sY * cZ + sX * sZ) * mat[2][3];
        temp[1][3] = cY * sZ * mat[0][3] + (sX * sY * sZ + cX * cZ) * mat[1][3] + (cX * sY * sZ - sX * cZ) * mat[2][3];
        temp[2][3] = -sY * mat[0][3] + sX * cY * mat[1][3] + cX * cY * mat[3][2];

        return temp;
    }

    template<typename T>
    matrix<4, 4, T> scale(const matrix<4, 4, T> &mat, const vector<3, T> &factor) {
        matrix<4, 4, T> temp = mat;

        temp[0][0] = temp[0][0] * factor.x;
        temp[1][0] = temp[1][0] * factor.x;
        temp[2][0] = temp[2][0] * factor.x;
        temp[3][0] = temp[3][0] * factor.x;

        temp[0][1] = temp[0][1] * factor.y;
        temp[1][1] = temp[1][1] * factor.y;
        temp[2][1] = temp[2][1] * factor.y;
        temp[3][1] = temp[3][1] * factor.y;

        temp[0][2] = temp[0][2] * factor.z;
        temp[1][2] = temp[1][2] * factor.z;
        temp[2][2] = temp[2][2] * factor.z;
        temp[3][2] = temp[3][2] * factor.z;

        return temp;
    }

    template<size_t M, size_t N, typename T>
    std::ostream &operator<<(std::ostream &s, const matrix<M, N, T> &mat) {
        for (size_t i = 0; i < M; ++i) {
            s << "[";
            for (size_t j = 0; j < N; ++j) {
                s << mat[i][j];
                if (j < N - 1) {
                    s << ", ";
                }
            }
            s << "]";
            if (i < M - 1)
                s << std::endl;
        }
        return s;
    }

}
