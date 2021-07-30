#pragma once
#include <array>
#include <type_traits>
#include <iostream>

namespace details {
    
    template <typename T, typename... Ts>
    struct is_contained : std::disjunction<std::is_same<T, Ts>...> {};

    template <typename T, typename... Ts>
    struct are_distinct
        : std::conjunction<std::negation<std::is_same<T, Ts>>...,
                           are_distinct<Ts...>> {};

    template <typename T>
    struct are_distinct<T> : std::true_type {};
}  // namespace details

namespace mls {
    template <size_t width, size_t height, typename... data_types>
    class matrix_tuple {
        static_assert(details::are_distinct<data_types...>::value,
                      "Types must be distinct");

       private:
        static constexpr size_t length = width * height;

        using storage_type = std::tuple<std::array<data_types, length>...>;

       public:
        template <typename... Ts>
        [[nodiscard]] std::tuple<Ts&...> get(size_t x, size_t y) {
            return std::tuple<Ts&...>{std::get<std::array<Ts, length>>(
                storage)[pos_to_index(x, y)]...};
        }
        
       private:
        size_t pos_to_index(size_t x, size_t y) { return x * width + y; }

       private:
        storage_type storage;
    };
}  // namespace mls