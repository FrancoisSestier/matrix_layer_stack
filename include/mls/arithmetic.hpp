namespace mls {

    template <typename T, typename tag>
    class arithmetic_type {
       public:
        using underlying_type = T;
        using type =arithmetic_type<underlying_type,tag>;
        arithmetic_type() = default;

        constexpr arithmetic_type(const underlying_type & value) noexcept(
            std::is_nothrow_copy_constructible<underlying_type>::value)
            : value_(value) {}

        constexpr arithmetic_type(underlying_type&& value) noexcept(
            std::is_nothrow_move_constructible<underlying_type>::value)
            : value_(std::move(value)) {}

        explicit operator underlying_type&() noexcept { return value_; }

        explicit operator const underlying_type&() const noexcept { return value_; }

        // equality
        bool operator!=(const type& other) const {
            return value_
                   != static_cast<underlying_type>(other);
        }

        bool operator==(const type& other) const {
            return value_
                   == static_cast<underlying_type>(other);
        }

        // unary
        [[nodiscard]] constexpr type operator+() const {
            return +value_;
        }
        [[nodiscard]] constexpr type operator-() const {
            return -value_;
        }

        // addition

        [[nodiscard]] type operator+(const type& other) noexcept {
            return value_
                   + static_cast<underlying_type>(other);
        }

        [[nodiscard]] type& operator+=(type& other) noexcept {
            return value_ += other;
        }

        // substraction

        [[nodiscard]] type operator-(const type& other) noexcept {
            return value_
                   - static_cast<underlying_type>(other);
        };

        [[nodiscard]] type& operator-=(type& other) noexcept {
            return value_ -= other;
        }

        // multiplication

        [[nodiscard]] type operator*(const type& other) noexcept {
            return value_
                   * static_cast<underlying_type>(other);
        };

        [[nodiscard]] type& operator*=(type& other) noexcept {
            return value_ *= other;
        }

        // division
        [[nodiscard]] type operator/(const type& other) noexcept {
            return value_
                   * static_cast<underlying_type>(other);
        };

        [[nodiscard]] type& operator/=(type& other) noexcept {
            return value_ /= other;
        }

        // decrementation
        [[nodiscard]] type& operator--() noexcept {
            --value_;
            return *this;
        };

        [[nodiscard]] type& operator--(int) noexcept {
            auto tmp = value_--;
            return *this;
        }

        // incrementation
        [[nodiscard]] type& operator++() noexcept {
            ++value_;
            return *this;
        };

        [[nodiscard]] type& operator++(int) noexcept {
            auto tmp = value_++;
            return tmp;
        }

        // modulo
        [[nodiscard]] type operator%(const type& other) noexcept {
            return value_
                   % static_cast<underlying_type>(other);
        };

        // bitwise
        [[nodiscard]] type operator~() noexcept {
            return ~value_;
        }

        [[nodiscard]] type operator&(const type& other) noexcept {
            return value_
                   & static_cast<underlying_type>(other);
        }

        [[nodiscard]] underlying_type operator|(const type& other) noexcept {
            return value_
                   | static_cast<underlying_type>(other);
        }

        [[nodiscard]] type operator^(const type& other) noexcept {
            return value_
                   ^ static_cast<underlying_type>(other);
        }

        [[nodiscard]] type operator<<(const type& other) noexcept {
            return value_
                   << static_cast<underlying_type>(other);
        }

        [[nodiscard]] type operator>>(const type& other) noexcept {
            return value_
                   >> static_cast<underlying_type>(other);
        }

        // compare

        bool operator>=(const type& other) noexcept {
            return value_
                   >= static_cast<underlying_type>(other);
        }

        bool operator>(const type& other) noexcept {
            return value_
                   > static_cast<underlying_type>(other);
        }

        bool operator<=(const type& other) noexcept {
            return value_
                   <= static_cast<underlying_type>(other);
        }

        bool operator<(const type& other) noexcept {
            return value_
                   < static_cast<underlying_type>(other);
        }

       private:
        underlying_type value_;
    };
}  // namespace mls
