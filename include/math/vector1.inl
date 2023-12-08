
#include <type_traits>

#include "vectorutils.hpp"

namespace showdown::math {
    
    template<typename T>
    requires std::is_arithmetic_v<T>
    constexpr T vector<1, T>::dot(const vector<1, T> &other) const {
        return showdown::math::dot(*this, other);
    }

} // namespace showdown::math
