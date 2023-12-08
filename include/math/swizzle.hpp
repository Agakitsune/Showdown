
#pragma once

#include <cstddef>

#include "vector.hpp"

namespace showdown::math {

    namespace _detail {
        
        template<size_t I>
        struct _swizzle {
            constexpr static size_t sindex = I;
            size_t index = I;
        };

    } // namespace _detail

    namespace arg {
        
        using X = _detail::_swizzle<0>;
        using Y = _detail::_swizzle<1>;
        using Z = _detail::_swizzle<2>;
        using W = _detail::_swizzle<3>;

        using R = _detail::_swizzle<0>;
        using G = _detail::_swizzle<1>;
        using B = _detail::_swizzle<2>;
        using A = _detail::_swizzle<3>;

        using S = _detail::_swizzle<0>;
        using T = _detail::_swizzle<1>;
        using P = _detail::_swizzle<2>;
        using Q = _detail::_swizzle<3>;

        template<size_t I>
        using Arg = _detail::_swizzle<I>;

    } // namespace swizzle
    
    template<typename... Args, size_t N, typename T>
    vector<sizeof...(Args), T> swizzle(const vector<N, T> &vec) {
        const T *data = vec.data();
        return vector<sizeof...(Args), T>(data[Args::sindex]...);
    }

    template<size_t N, typename T, typename... Args>
    vector<sizeof...(Args), T> swizzle(const vector<N, T> &vec, const Args&... param) {
        const T *data = vec.data();
        return vector<sizeof...(Args), T>(data[param.index]...);
    }

}
