
#pragma once

#include <type_traits>
#include <cstddef>

namespace showdown::math {
    
    template<size_t N, typename T>
    requires std::is_arithmetic_v<T>
    class vector;

    namespace _meta {

        template<typename T>
        struct _argumentSize {
            static constexpr size_t value = 1;
        };

        template<size_t N, typename T>
        struct _argumentSize<vector<N, T>> {
            static constexpr size_t value = N;
        };

        template<typename... T>
        struct argumentSize {
            static constexpr size_t value = (0 + ... + _argumentSize<T>::value);
        };
    }

} // namespace showdown::math
