
#include <type_traits>

#include "vectorutils.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    constexpr T vector<3, T>::dot(const vector<3, T> &other) const {
        return showdown::math::dot(*this, other);
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    constexpr vector<3, T> vector<3, T>::cross(const vector<3, T> &other) const {
        return showdown::math::cross(*this, other);
    }

} // namespace showdown::math
