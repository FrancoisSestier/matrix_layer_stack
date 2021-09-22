#pragma once
#include <array>
#include <iostream>
#include <type_traits>

namespace details {

    template <typename T, typename... Ts>
    struct is_contained : std::disjunction<std::is_same<T, Ts>...> {};

    template <typename T, typename... Ts>
    struct are_distinct
        : std::conjunction<std::negation<std::is_same<T, Ts>>...,
                           are_distinct<Ts...>> {};

    template <typename T>
    struct are_distinct<T> : std::true_type {};

    template <typename... Ts>
    struct are_const : std::conjunction<std::is_const<Ts>...> {};

    template <typename... Ts>
    inline constexpr bool are_const_v = are_const<Ts...>::value;

    template <typename... Ts>
    concept const_value = are_const_v<Ts...>;

}  // namespace details

namespace mls {
    template <size_t mt_width, size_t mt_height, typename... mt_data_types>
    class matrix_tuple {
        static_assert(details::are_distinct<mt_data_types...>::value,
                      "Types must be distinct");

       public:
        
        inline static constexpr size_t width = mt_width;
        inline static constexpr size_t height = mt_height;
        inline static constexpr size_t size = width * height;

        using storage_type = std::tuple<std::array<mt_data_types, size>...>;

        template <typename... Ts>
        requires(sizeof...(Ts) > 1)
            [[nodiscard]] std::tuple<Ts&...> get(size_t x, size_t y) {
            return std::tuple<Ts&...>{get<Ts>(x, y)...};
        }

        template <details::const_value T>
        [[nodiscard]] T& get(size_t x, size_t y) const {
            return std::get<std::array<std::remove_cv_t<T>, size>>(
                storage)[pos_to_index(x, y)];
        }

        template <details::const_value... Ts>
        requires(sizeof...(Ts) > 1)
            [[nodiscard]] std::tuple<Ts&...> get(size_t x, size_t y) const {
            return std::tuple<Ts&...>{get<Ts>(x, y)...};
        }

        template <typename T>
        [[nodiscard]] std::array<T, size>& underlying() {
            return std::get<std::array<std::remove_cvref_t<T>, size>>(storage);
        }

        template <typename T>
        [[nodiscard]] const std::array<T, size>& underlying() const {
            return std::get<std::array<std::remove_cvref_t<T>, size>>(storage);
        }

        template <typename T>
        [[nodiscard]] T* raw() {
            return std::get<std::array<std::remove_cvref_t<T>, size>>(storage)
                .data();
        }

       private:
        size_t pos_to_index(size_t x, size_t y) const { return x * width + y; }

        storage_type storage;
    };
}  // namespace mls