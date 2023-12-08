
#pragma once

#include "vector1.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

#include "matrix.hpp"

#include "vectorutils.hpp"
#include "swizzle.hpp"

namespace showdown::math {
    
    template<typename T>
    using vec1 = vector<1, T>;

    template<typename T>
    using vec2 = vector<2, T>;

    template<typename T>
    using vec3 = vector<3, T>;

    template<typename T>
    using vec4 = vector<4, T>;

    using vec1i = vec1<int>;
    using vec2i = vec2<int>;
    using vec3i = vec3<int>;
    using vec4i = vec4<int>;

    using vec1u = vec1<unsigned int>;
    using vec2u = vec2<unsigned int>;
    using vec3u = vec3<unsigned int>;
    using vec4u = vec4<unsigned int>;

    using vec1f = vec1<float>;
    using vec2f = vec2<float>;
    using vec3f = vec3<float>;
    using vec4f = vec4<float>;

    using vec1d = vec1<double>;
    using vec2d = vec2<double>;
    using vec3d = vec3<double>;
    using vec4d = vec4<double>;

    using vec1b = vec1<bool>;
    using vec2b = vec2<bool>;
    using vec3b = vec3<bool>;
    using vec4b = vec4<bool>;

    using vec1c = vec1<char>;
    using vec2c = vec2<char>;
    using vec3c = vec3<char>;
    using vec4c = vec4<char>;

    using vec1uc = vec1<unsigned char>;
    using vec2uc = vec2<unsigned char>;
    using vec3uc = vec3<unsigned char>;
    using vec4uc = vec4<unsigned char>;

    using vec1s = vec1<short>;
    using vec2s = vec2<short>;
    using vec3s = vec3<short>;
    using vec4s = vec4<short>;

    using vec1us = vec1<unsigned short>;
    using vec2us = vec2<unsigned short>;
    using vec3us = vec3<unsigned short>;
    using vec4us = vec4<unsigned short>;

    using vec1l = vec1<long>;
    using vec2l = vec2<long>;
    using vec3l = vec3<long>;
    using vec4l = vec4<long>;

    using vec1ul = vec1<unsigned long>;
    using vec2ul = vec2<unsigned long>;
    using vec3ul = vec3<unsigned long>;
    using vec4ul = vec4<unsigned long>;

    using vec1ll = vec1<long long>;
    using vec2ll = vec2<long long>;
    using vec3ll = vec3<long long>;
    using vec4ll = vec4<long long>;

    using vec1ull = vec1<unsigned long long>;
    using vec2ull = vec2<unsigned long long>;
    using vec3ull = vec3<unsigned long long>;
    using vec4ull = vec4<unsigned long long>;

    using vec1f32 = vec1<float>;
    using vec2f32 = vec2<float>;
    using vec3f32 = vec3<float>;
    using vec4f32 = vec4<float>;

    using vec1f64 = vec1<double>;
    using vec2f64 = vec2<double>;
    using vec3f64 = vec3<double>;
    using vec4f64 = vec4<double>;

    using vec1f128 = vec1<long double>;
    using vec2f128 = vec2<long double>;
    using vec3f128 = vec3<long double>;
    using vec4f128 = vec4<long double>;

} // namespace showdown::gl
