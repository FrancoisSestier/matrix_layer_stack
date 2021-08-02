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
    template <size_t mt_width, size_t mt_height, typename... mt_data_types>
    class matrix_tuple {
        static_assert(details::are_distinct<mt_data_types...>::value,
                      "Types must be distinct");

       public:
        inline static constexpr size_t width = mt_width;
        inline static constexpr size_t height = mt_height;
        inline static constexpr size_t length = width * height;


        using storage_type = std::tuple<std::array<mt_data_types, length>...>;

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