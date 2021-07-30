namespace mls {
    
    template <typename T, typename tag>
    class arithmetic_type {
       public:
        using underlying_type = T;
        arithmetic_type() = default;

        constexpr arithmetic_type(T const& value) noexcept(
            std::is_nothrow_copy_constructible<T>::value)
            : value_(value) {}

        constexpr arithmetic_type(T&& value) noexcept(
            std::is_nothrow_move_constructible<T>::value)
            : value_(std::move(value)) {}

        explicit operator T&() noexcept { return value_; }

        explicit operator const T&() const noexcept { return value_; }

        // equality
        bool operator!=(const T& other) const {
            return static_cast<underlying_type>(value_)
                   != static_cast<underlying_type>(other);
        }

        bool operator==(const T& other) const {
            return static_cast<underlying_type>(value_)
                   == static_cast<underlying_type>(other);
        }

        // unary
        [[nodiscard]] constexpr T operator+() const {
            return +static_cast<underlying_type>(value_);
        }
        [[nodiscard]] constexpr T operator-() const {
            return -static_cast<underlying_type>(value_);
        }

        // addition

        [[nodiscard]] T operator+(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   + static_cast<underlying_type>(other);
        }

        [[nodiscard]] T& operator+=(T& other) noexcept {
            return value_ += other;
        }

        // substraction

        [[nodiscard]] T operator-(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   - static_cast<underlying_type>(other);
        };

        [[nodiscard]] T& operator-=(T& other) noexcept {
            return value_ -= other;
        }

        // multiplication

        [[nodiscard]] T operator*(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   * static_cast<underlying_type>(other);
        };

        [[nodiscard]] T& operator*=(T& other) noexcept {
            return value_ *= other;
        }

        // division
        [[nodiscard]] T operator/(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   * static_cast<underlying_type>(other);
        };

        [[nodiscard]] T& operator/=(T& other) noexcept {
            return value_ /= other;
        }

        // decrementation
        [[nodiscard]] T& operator--() noexcept {
            --static_cast<underlying_type>(value_);
            return value_;
        };

        [[nodiscard]] T& operator--(int) noexcept {
            auto tmp = static_cast<underlying_type>(value_)--;
            return tmp;
        }

        // incrementation
        [[nodiscard]] T& operator++() noexcept {
            ++static_cast<underlying_type>(value_);
            return value_;
        };

        [[nodiscard]] T& operator++(int) noexcept {
            auto tmp = static_cast<underlying_type>(value_)++;
            return tmp;
        }

        // modulo
        [[nodiscard]] T operator%(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   % static_cast<underlying_type>(other);
        };

        // bitwise
        [[nodiscard]] T operator~() noexcept {
            return ~static_cast<underlying_type>(value_);
        }

        [[nodiscard]] T operator&(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   & static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator|(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   | static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator^(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   ^ static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator<<(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   << static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator>>(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   >> static_cast<underlying_type>(other);
        }

        // compare

        [[nodiscard]] T operator>=(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   >= static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator>(const T& other) noexcept {
                       return static_cast<underlying_type>(value_)
                   > static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator<=(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   <= static_cast<underlying_type>(other);
        }

        [[nodiscard]] T operator<(const T& other) noexcept {
            return static_cast<underlying_type>(value_)
                   < static_cast<underlying_type>(other);
        }

       private:
        underlying_type value_;
    };
}  // namespace mls
