#pragma once
#include <concepts>
#include <mls/arithmetic.hpp>

namespace mls {

    // integral

    template <std::integral T, typename Tag>
    using strong_integer = arithmetic_type<T, Tag>;

    template <typename Tag>
    using s_int = strong_integer<int, Tag>;

    template <typename Tag>
    using s_short = strong_integer<short, Tag>;

    template <typename Tag>
    using s_long = strong_integer<long, Tag>;

    template <typename Tag>
    using s_long_long = strong_integer<long long, Tag>;

    template <typename Tag>
    using s_int8_t = strong_integer<int8_t, Tag>;

    template <typename Tag>
    using s_int16_t = strong_integer<int16_t, Tag>;

    template <typename Tag>
    using s_int32_t = strong_integer<int32_t, Tag>;

    template <typename Tag>
    using s_int64_t = strong_integer<int64_t, Tag>;

    template <typename Tag>
    using s_uint8_t = strong_integer<uint8_t, Tag>;

    template <typename Tag>
    using s_uint16_t = strong_integer<uint16_t, Tag>;

    template <typename Tag>
    using s_uint32_t = strong_integer<uint32_t, Tag>;

    template <typename Tag>
    using s_uint64_t = strong_integer<uint64_t, Tag>;

    // floating_point
    template <std::floating_point T, typename Tag>
    using strong_floating_point = arithmetic_type<T, Tag>;

    template <typename Tag>
    using s_double = strong_floating_point<double, Tag>;

    template <typename Tag>
    using s_float = strong_floating_point<float, Tag>;



}  // namespace mls
