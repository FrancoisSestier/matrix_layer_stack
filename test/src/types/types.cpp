#include <gtest/gtest.h>

#include <mls/strong_types.hpp>

using namespace mls;

using elevation = s_int16_t<struct elevation_tag>;
using tile_id = s_int32_t<struct tile_id_tag>;

TEST(MLS, INT_TYPES) {
    ASSERT_NE(typeid(elevation).hash_code(), typeid(tile_id).hash_code());

    elevation el(51);

    tile_id tid(5);
};

TEST(MLS, SIZE_OF) {
    ASSERT_EQ(sizeof(elevation), sizeof(int16_t));
    ASSERT_EQ(sizeof(tile_id), sizeof(int32_t));
}

TEST(MLS, ASSIGNMENT) {
    elevation el = 51;
    elevation& el2 = el;
    elevation el3 = el;
}

TEST(MLS, COMPARE) {
    elevation el = 0;
    elevation el2 = 10;
    ASSERT_TRUE(el < el2);
    ASSERT_TRUE(el < 15);
    ASSERT_TRUE(el <= el2);
    ASSERT_TRUE(el >= 0);
    ASSERT_TRUE(el2 > 9);
    ASSERT_TRUE(el2 > elevation(5));
    ASSERT_EQ(el, 0);
    ASSERT_NE(el, 10);
}

TEST(MLS, CAST) {
    int i = -5;
    elevation el2 = static_cast<elevation>(i);
    ASSERT_EQ(el2, -5);
    elevation::underlying_type i2 = static_cast<elevation::underlying_type>(el2);
}
