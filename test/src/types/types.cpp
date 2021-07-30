#include <gtest/gtest.h>
#include <mls/strong_types.hpp>

using namespace mls;

    using elevation = s_int16_t<struct elevation_tag>;
    using tile_id = s_int32_t<struct tile_id_tag>;

TEST(MLS,INT_TYPES) {
    ASSERT_NE(typeid(elevation).hash_code(),typeid(tile_id).hash_code());

    elevation el(51);
    
    tile_id tid(5);
};

TEST(MLS,SIZE_OF){
    ASSERT_EQ(sizeof(elevation),sizeof(int16_t));
    ASSERT_EQ(sizeof(tile_id),sizeof(int32_t));

}