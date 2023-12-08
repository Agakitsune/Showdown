
#pragma once

#include <type_traits>

#include "gl/VertexArray.hpp"
#include "math/math.hpp"

namespace showdown::utils {

    template<typename T>
    struct normalize {
        using type = T;
    };

    namespace __private {
        
        template<typename T>
        struct vertexAttribute;

        template<bool value, typename T, T True, T False>
        struct if_;

        template<typename T, T True, T False>
        struct if_<true, T, True, False> {
            static constexpr T value = True;
        };

        template<typename T, T True, T False>
        struct if_<false, T, True, False> {
            static constexpr T value = False;
        };

        template<typename T>
        struct vertexAttribute<normalize<T>> {
            static constexpr bool normal = true;
            static constexpr size_t n = vertexAttribute<T>::n;
            static constexpr gl::VertexAttributeType type = vertexAttribute<T>::type;
        };

        template<typename T>
        requires std::is_arithmetic_v<T>
        struct vertexAttribute<T> {
            static constexpr bool normal = false;
            static constexpr size_t n = 1;
            static constexpr size_t size = sizeof(T);
            static constexpr gl::VertexAttributeType type = if_<
                std::is_integral_v<T>,
                gl::VertexAttributeType,
                if_<std::is_signed_v<T>,
                    gl::VertexAttributeType,
                    if_<sizeof(T) == 1, 
                        gl::VertexAttributeType,
                        gl::VertexAttributeType::Byte,
                        if_<sizeof(T) == 2,
                            gl::VertexAttributeType,
                            gl::VertexAttributeType::Short,
                            gl::VertexAttributeType::Int
                        >::value
                    >::value,
                    if_<sizeof(T) == 1,
                        gl::VertexAttributeType,
                        gl::VertexAttributeType::UnsignedByte,
                        if_<sizeof(T) == 2,
                            gl::VertexAttributeType,
                            gl::VertexAttributeType::UnsignedShort,
                            gl::VertexAttributeType::UnsignedInt
                        >::value
                    >::value
                >::value,
                if_<sizeof(T) == 4,
                    gl::VertexAttributeType,
                    gl::VertexAttributeType::Float,
                    gl::VertexAttributeType::Double
                >::value
            >::value;
        };

        template<size_t N, typename T>
        struct vertexAttribute<math::vector<N, T>> {
            static constexpr bool normal = false;
            static constexpr size_t n = N;
            static constexpr size_t size = sizeof(T) * N;
            static constexpr gl::VertexAttributeType type = vertexAttribute<T>::type;
        };

    } // namespace __private
    

    template<typename... T>
    void useVertex(GLuint index) {
        constexpr size_t stride = (0 + ... + __private::vertexAttribute<T>::size);
        size_t offset = 0;
        ((
            gl::vertexAttribPointer(index++, __private::vertexAttribute<T>::n, __private::vertexAttribute<T>::type, __private::vertexAttribute<T>::normal, stride, offset),
            offset += __private::vertexAttribute<T>::size
        ), ...);
    }

    void disableAll();

} // namespace showdown::utils
